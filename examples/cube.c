/*******************************************************************************
 * The MIT License (MIT)
 *
 * Copyright (c) 2015-present Lars Schütz
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/
#include <stdbool.h>
#include <stdio.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define GLA_IMPLEMENTATION
#include "../gla/gla.h"
#define CGM_IMPLEMENTATION
#include <cgm/cgm.h>

void clean_up_glfw(GLFWwindow *window);

void error_cb(int error, const char *description);

void framebuffer_size_cb(GLFWwindow *window, int width, int height);

bool init(GLFWwindow **window, int window_width, int window_height,
        const char *window_title);

void key_cb(GLFWwindow *window, int key, int scancode, int action, int mods);

void update(double elapsed_frame_time);

void render(GLFWwindow *window);

static GLuint cube_vao = 0;
static GLuint cube_program = 0;
static mat4 view;
static mat4 proj;
static GLint mvp_location = -1;
static float cube_y_rotation_rad = 0.0f;
static bool do_render_wireframe = true;

// -----------------------------------------------------------------------------
int main(int argc, char **argv)
{
    glfwSetErrorCallback(error_cb);

    // Initialize the graphics systems
    GLFWwindow *window = NULL;
    if (!init(&window, 1024, 768, "GLA -- Cube")) {
        fprintf(stderr, "Error: Unable to initialize the graphics system\n");
        clean_up_glfw(window);
        return 1;
    }

    // Set callbacks up
    glfwSetKeyCallback(window, key_cb);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_cb);

    // Set geometry up and transfer it to the graphics card
    // Indexed drawing
    /*
          7----6
         /|   /|
        3----2 |
        | 4--|-5
        |/   |/
        0----1
    */
    GLfloat vertices[] = {
        -0.5f, -0.5f,  0.5f, // 0
         0.5f, -0.5f,  0.5f, // 1
         0.5f,  0.5f,  0.5f, // 2
        -0.5f,  0.5f,  0.5f, // 3
        -0.5f, -0.5f, -0.5f, // 4
         0.5f, -0.5f, -0.5f, // 5
         0.5f,  0.5f, -0.5f, // 6
        -0.5f,  0.5f, -0.5f, // 7
    };
    GLuint indices[] = {
        // Face 1
        0, 1, 2,
        0, 2, 3,
        // Face 2
        1, 5, 6,
        1, 6, 2,
        // Face 3
        5, 4, 7,
        5, 7, 6,
        // Face 4
        4, 0, 3,
        4, 3, 7,
        // Face 5
        1, 0, 4,
        1, 4, 5,
        // Face 6
        3, 2, 6,
        3, 6, 7
    };

    // Vertex buffer object
    GLuint cube_vbo = 0;
    glGenBuffers(1, &cube_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, cube_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Element buffer object
    GLuint cube_ebo = 0;
    glGenBuffers(1, &cube_ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cube_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
                GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // Vertex array object
    cube_vao = 0;
    glGenVertexArrays(1, &cube_vao);
    glBindVertexArray(cube_vao);
    glBindBuffer(GL_ARRAY_BUFFER, cube_vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cube_ebo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), NULL);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Create shaders and shader programs
    GLuint vert_shader =
        gla_build_shader_from_file("cube_vs.glsl", GL_VERTEX_SHADER);
    if (!gla_check_shader_build(vert_shader)) {
        gla_delete_shader(vert_shader);
        clean_up_glfw(window);
        return 1;
    }

    GLuint frag_shader =
        gla_build_shader_from_file("cube_fs.glsl", GL_FRAGMENT_SHADER);
    if (!gla_check_shader_build(frag_shader)) {
        gla_delete_shader(frag_shader);
        clean_up_glfw(window);
        return 1;
    }

    cube_program = gla_build_program(vert_shader, 0, 0, 0, frag_shader);
    if (!gla_check_program_build(cube_program, GL_LINK_STATUS)) {
        gla_delete_shader(vert_shader);
        gla_delete_shader(frag_shader);
        gla_delete_program(cube_program);
        clean_up_glfw(window);
        return 1;
    }

    gla_delete_shader(vert_shader);
    gla_delete_shader(frag_shader);

    // Model, view and projection matrices
    vec3 camera_eye = vec3_3f(0.0f, 2.0f, 2.0f);
    vec3 camera_center = vec3_3f(0.0f, 0.0f, 0.0f);
    vec3 camera_up = vec3_3f(0.0f, 2.0f, -2.0f);
    mat4 model = mat4_identity();
    view = mat4_look_at(camera_eye, camera_center, camera_up);
    proj = mat4_perspective(65.0f, 1.25f, 0.1f, 100.0f);
    mat4 mv = mat4_mul_mat4(view, model);
    mat4 mvp = mat4_mul_mat4(proj, mv);
    mvp_location = glGetUniformLocation(cube_program, "mvp");

    glUseProgram(cube_program);
    glUniformMatrix4fv(mvp_location, 1, GL_FALSE, mvp.m);
    glUseProgram(0);

    // Enter main loop
    double previous_time = glfwGetTime();
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        double current_time = glfwGetTime();
        double elapsed_frame_time = current_time - previous_time;
        previous_time = current_time;
        update(elapsed_frame_time);
        render(window);
        glfwSwapBuffers(window);
    }

    // Clean up and terminate application
    gla_delete_program(cube_program);
    clean_up_glfw(window);
    return 0;
}

// -----------------------------------------------------------------------------
void clean_up_glfw(GLFWwindow *window)
{
    if (window) {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}

// -----------------------------------------------------------------------------
void error_cb(int error, const char *description)
{
    fprintf(stderr, "Error: %s (error code %d)\n", description, error);
}

// -----------------------------------------------------------------------------
void framebuffer_size_cb(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// -----------------------------------------------------------------------------
bool init(GLFWwindow **window, int window_width, int window_height,
        const char *window_title)
{
    if (!glfwInit()) {
        fprintf(stderr, "Error: Unable to initialize GLFW\n");
        return false;
    }

    *window =
        glfwCreateWindow(window_width, window_height, window_title, NULL, NULL);
    if (!window) {
        fprintf(stderr, "Error: Unable to create window\n");
        return false;
    }

    glfwMakeContextCurrent(*window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        fprintf(stderr, "Error: Unable to initialize OpenGL context\n");
        return false;
    }

    return true;
}

// -----------------------------------------------------------------------------
void key_cb(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS) {
        switch (key) {
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(window, GL_TRUE);
            break;
        case GLFW_KEY_W:
            do_render_wireframe = !do_render_wireframe;
            break;
        default:
            break;
        }
    }
}

// -----------------------------------------------------------------------------
void update(double elapsed_frame_time)
{
    cube_y_rotation_rad += elapsed_frame_time;
    if (cube_y_rotation_rad >= CGM_2_PI) {
        cube_y_rotation_rad = 0.0f;
    }

    mat4 model = mat4_rotate_y(cube_y_rotation_rad);
    mat4 mv = mat4_mul_mat4(view, model);
    mat4 mvp = mat4_mul_mat4(proj, mv);

    glUseProgram(cube_program);
    glUniformMatrix4fv(mvp_location, 1, GL_FALSE, mvp.m);
    glUseProgram(0);
}

// -----------------------------------------------------------------------------
void render(GLFWwindow *window)
{
    glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (do_render_wireframe) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    glUseProgram(cube_program);
    glBindVertexArray(cube_vao);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, NULL);
    glBindVertexArray(0);
    glUseProgram(0);
}
