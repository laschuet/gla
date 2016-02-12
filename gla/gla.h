/*******************************************************************************
 * The MIT License (MIT)
 *
 * Copyright (c) 2015, 2016 Lars Schütz
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

#ifndef GLA_H_INCLUDE
#define GLA_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#ifdef GLA_STATIC
#define GLA_LINKAGE static
#else
#define GLA_LINKAGE
#endif // GLA_STATIC

/**
 * \brief Creates and links a program object given a compute shader object.
 * \param compute_shader Specifies the compute shader object that gets attached
 *                       to the program object.
 * \return The program object.
 * \note The compute shader object gets detached after linking.
 */
GLA_LINKAGE GLuint gla_build_compute_program(GLuint compute_shader);

/**
 * \brief Creates and links a program object given the name of the shader file
 *        that contains the source code to be used.
 * \param filename Specifies the name of the file containing the compute shader
 *                 source code.
 * \return The program object.
 * \note The internally built compute shader object gets detached after linking.
 */
GLA_LINKAGE GLuint gla_build_compute_program_from_file(const GLchar *filename);

/**
 * \brief Creates and links a program object given some shader objects.
 * \param vertex_shader Specifies the vertex shader object that gets attached to
 *                      the program object.
 * \param tessellation_control_shader Specifies the tessellation control shader
 *                                    object that gets attached to the program
 *                                    object.
 * \param tessellation_evaluation_shader Specifies the tessellation evaluation
 *                                       shader object that gets attached to the
 *                                       program object.
 * \param geometry_shader Specifies the geometry shader object that gets
 *                        attached to the program object.
 * \param fragment_shader Specifies the fragment shader object that gets
 *                        attached to the program object.
 * \return The program object.
 * \note The shader objects get detached after linking.
 */
GLA_LINKAGE GLuint gla_build_program(GLuint vertex_shader,
                                     GLuint tessellation_control_shader,
                                     GLuint tessellation_evaluation_shader,
                                     GLuint geometry_shader,
                                     GLuint fragment_shader);

/**
 * \brief Creates and links a program object given the names of the shader
 *        files that contain the source code to be used.
 * \param vert_filename Specifies the name of the file containing the vertex
 *                      shader source code.
 * \param tess_ctrl_filename Specifies the name of the file containing the
 *                           tessellation control shader source code.
 * \param tess_eval_filename Specifies the name of the file containing the
 *                           tessellation evaluation shader source code.
 * \param geom_filename Specifies the name of the file containing the geometry
 *                      shader source code.
 * \param frag_filename Specifies the name of the file containing the fragment
 *                      shader source code.
 * \return The program object.
 * \note The internally built shader objects get detached after linking.
 */
GLA_LINKAGE GLuint gla_build_program_from_file(const GLchar *vert_filename,
                                               const GLchar *tess_ctrl_filename,
                                               const GLchar *tess_eval_filename,
                                               const GLchar *geom_filename,
                                               const GLchar *frag_filename,
                                               GLboolean check_shaders);

/**
 * \brief Creates and compiles a shader object given the source code to be used.
 * \param source Specifies the source code to be compiled.
 * \param shader_type Specifies the type of shader to be build.
 * \return The shader object.
 */
GLA_LINKAGE GLuint gla_build_shader(const GLchar *source, GLenum shader_type);

/**
 * \brief Creates and compiles a shader object given the name of the shader file
 *        that contains the source code to be used.
 * \param filename Specifies the filename that holds the source code to be
 *                 compiled.
 * \param shader_type Specifies the type of shader to be build.
 * \return The shader object.
 */
GLA_LINKAGE GLuint gla_build_shader_from_file(const GLchar *filename,
                                              GLenum shader_type);

/**
 * \brief Checks the link or validation status of a program object, and prints
 *        the program object info log to the standard output if an error
 *        occurred.
 * \param program Specifies the program object that gets checked.
 * \param pname Specifies the object parameter. Accepted symbolic names are
 *        \c GL_LINK_STATUS and \c GL_VALIDATE_STATUS.
 * \return Returns \c GL_TRUE if the last link or validation operation on
 *         \p program was successful, and \c GL_FALSE otherwise.
 */
GLA_LINKAGE GLint gla_check_program_build(GLuint program, GLenum pname);

/**
 * \brief Checks the compile status of a shader object and prints the shader
 *        object info log to the standard output if an error occurred.
 * \param shader Specifies the shader object that gets checked.
 * \return Returns \c GL_TRUE if the last compile operation on \p shader was
 *         successful, and \c GL_FALSE otherwise.
 */
GLA_LINKAGE GLint gla_check_shader_build(GLuint shader);

/**
 * \brief Deletes a program object.
 * \param program Specifies the program object to be deleted.
 * \note This function is the counterpart to
 *       gla_build_program(GLuint, GLuint) and
 *       gla_build_program_from_file(const GLchar *, const GLchar *,
 *                                   const GLchar *, const GLchar *,
 *                                   const GLchar *).
 */
GLA_LINKAGE void gla_delete_program(GLuint program);

/**
 * \brief Deletes a shader object.
 * \param shader Specifies the shader object to be deleted.
 * \note This function is the counterpart to
 *       gla_build_shader(const GLchar *, GLenum) and
 *       gla_build_shader_from_file(const GLchar *, GLenum).
 */
GLA_LINKAGE void gla_delete_shader(GLuint shader);

/**
 * \brief Prints the program object's information log to the standard output.
 * \param program Specifies the program object whose information log is to be
 *                printed.
 */
GLA_LINKAGE void gla_print_program_info_log(GLuint program);

/**
 * \brief Prints the shader object's information log to the standard output.
 * \param shader Specifies the shader object whose information log is to be
 *               printed.
 */
GLA_LINKAGE void gla_print_shader_info_log(GLuint shader);

/**
 * \brief Loads and returns the contents of a text file.
 * \param filename Specifies the name of the file to be read.
 * \return The file's contents.
 * \note The returned pointer must be deallocated.
 */
GLA_LINKAGE GLchar *gla_read_text_file(const GLchar *filename);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // GLA_H_INCLUDE

#ifdef GLA_IMPLEMENTATION
#undef GLA_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -----------------------------------------------------------------------------
GLA_LINKAGE GLuint gla_build_compute_program(GLuint compute_shader)
{
    if (!compute_shader) {
        fprintf(stderr, "Error: Compute program building: "
                        "Program must contain a compute shader\n");
        return 0;
    }

    GLuint program = glCreateProgram();
    glAttachShader(program, compute_shader);
    glLinkProgram(program);
    glDetachShader(program, compute_shader);
    return program;
}

// -----------------------------------------------------------------------------
GLA_LINKAGE GLuint gla_build_compute_program_from_file(const GLchar *filename)
{
    GLuint comp = 0;
    if (filename) {
        comp = gla_build_shader_from_file(filename, GL_COMPUTE_SHADER);
    }
    return gla_build_compute_program(comp);
}

// -----------------------------------------------------------------------------
GLA_LINKAGE GLuint gla_build_program(GLuint vertex_shader,
                                     GLuint tessellation_control_shader,
                                     GLuint tessellation_evaluation_shader,
                                     GLuint geometry_shader,
                                     GLuint fragment_shader)
{
    if (!(vertex_shader && fragment_shader)) {
        fprintf(stderr, "Error: Program building: "
                        "Program must contain at least a vertex shader and a "
                        "fragment shader\n");
        return 0;
    }

    GLuint program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    if (tessellation_control_shader) {
        glAttachShader(program, tessellation_control_shader);
    }
    if (tessellation_evaluation_shader) {
        glAttachShader(program, tessellation_evaluation_shader);
    }
    if (geometry_shader) {
        glAttachShader(program, geometry_shader);
    }
    glAttachShader(program, fragment_shader);

    glLinkProgram(program);

    glDetachShader(program, vertex_shader);
    if (tessellation_control_shader) {
        glDetachShader(program, tessellation_control_shader);
    }
    if (tessellation_evaluation_shader) {
        glDetachShader(program, tessellation_evaluation_shader);
    }
    if (geometry_shader) {
        glDetachShader(program, geometry_shader);
    }
    glDetachShader(program, fragment_shader);

    return program;
}

// -----------------------------------------------------------------------------
GLA_LINKAGE GLuint gla_build_program_from_file(const GLchar *vert_filename,
                                               const GLchar *tess_ctrl_filename,
                                               const GLchar *tess_eval_filename,
                                               const GLchar *geom_filename,
                                               const GLchar *frag_filename,
                                               GLboolean check_shaders)
{
    GLuint vert = 0;
    GLuint tess_ctrl = 0;
    GLuint tess_eval = 0;
    GLuint geom = 0;
    GLuint frag = 0;

    if (vert_filename) {
        vert = gla_build_shader_from_file(vert_filename, GL_VERTEX_SHADER);
    }
    if (tess_ctrl_filename) {
        tess_ctrl = gla_build_shader_from_file(tess_ctrl_filename,
                                               GL_TESS_CONTROL_SHADER);
    }
    if (tess_eval_filename) {
        tess_eval = gla_build_shader_from_file(tess_eval_filename,
                                               GL_TESS_EVALUATION_SHADER);
    }
    if (geom_filename) {
        geom = gla_build_shader_from_file(geom_filename, GL_GEOMETRY_SHADER);
    }
    if (frag_filename) {
        frag = gla_build_shader_from_file(frag_filename, GL_FRAGMENT_SHADER);
    }

    if (check_shaders) {
        GLboolean success = GL_TRUE;

        if (vert_filename && !gla_check_shader_build(vert)) {
            fprintf(stderr, "Error: Program building: "
                            "Shader (\"%s\") build error. "
                            "See shader info log\n", vert_filename);
            gla_delete_shader(vert);
            success = GL_FALSE;
        }
        if (tess_ctrl_filename && !gla_check_shader_build(tess_ctrl)) {
            fprintf(stderr, "Error: Program building: "
                            "Shader (\"%s\") build error. "
                            "See shader info log\n", tess_ctrl_filename);
            gla_delete_shader(tess_ctrl);
            success = GL_FALSE;
        }
        if (tess_eval_filename && !gla_check_shader_build(tess_eval)) {
            fprintf(stderr, "Error: Program building: "
                            "Shader (\"%s\") build error. "
                            "See shader info log\n", tess_eval_filename);
            gla_delete_shader(tess_eval);
            success = GL_FALSE;
        }
        if (geom_filename && !gla_check_shader_build(geom)) {
            fprintf(stderr, "Error: Program building: "
                            "Shader (\"%s\") build error. "
                            "See shader info log\n", geom_filename);
            gla_delete_shader(geom);
            success = GL_FALSE;
        }
        if (frag_filename && !gla_check_shader_build(frag)) {
            fprintf(stderr, "Error: Shader building: "
                            "Shader (\"%s\") build error. "
                            "See shader info log\n", frag_filename);
            gla_delete_shader(frag);
            success = GL_FALSE;
        }

        if (!success) {
            return 0;
        }
    }

    return gla_build_program(vert, tess_ctrl, tess_eval, geom, frag);
}

// -----------------------------------------------------------------------------
GLA_LINKAGE GLuint gla_build_shader(const GLchar *source, GLenum shader_type)
{
    GLuint shader = glCreateShader(shader_type);
    glShaderSource(shader, 1, (const GLchar**) &source, NULL);
    glCompileShader(shader);
    return shader;
}

// -----------------------------------------------------------------------------
GLA_LINKAGE GLuint gla_build_shader_from_file(const GLchar *filename,
                                              GLenum shader_type)
{
    GLchar *shader_source = gla_read_text_file(filename);
    if (!shader_source) {
        fprintf(stderr, "Error: Shader (\"%s\") building: "
                        "Unable to load source\n", filename);
        return 0;
    }
    GLuint shader = gla_build_shader(shader_source, shader_type);
    free(shader_source);
    shader_source = NULL;
    return shader;
}

// -----------------------------------------------------------------------------
GLA_LINKAGE GLint gla_check_program_build(GLuint program, GLenum pname)
{
    if (pname != GL_LINK_STATUS || pname != GL_VALIDATE_STATUS) {
        return GL_INVALID_ENUM;
    }

    GLint success = GL_FALSE;
    glGetProgramiv(program, pname, &success);
    if (!success) {
        gla_print_program_info_log(program);
    }
    return success;
}

// -----------------------------------------------------------------------------
GLA_LINKAGE GLint gla_check_shader_build(GLuint shader)
{
    GLint success = GL_FALSE;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        gla_print_shader_info_log(shader);
    }
    return success;
}

// -----------------------------------------------------------------------------
GLA_LINKAGE void gla_delete_program(GLuint program)
{
    glDeleteProgram(program);
    program = 0;
}

// -----------------------------------------------------------------------------
GLA_LINKAGE void gla_delete_shader(GLuint shader)
{
    glDeleteShader(shader);
    shader = 0;
}

// -----------------------------------------------------------------------------
GLA_LINKAGE void gla_print_program_info_log(GLuint program)
{
    GLint info_log_length = 0;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &info_log_length);

    GLchar *info_log = malloc(info_log_length);
    if (!info_log) {
        fprintf(stderr, "Error: Program (id = %d) info log printing: "
                        "Unable to allocate memory for the info log\n",
                        program);
        return;
    }
    glGetProgramInfoLog(program, info_log_length, NULL, info_log);
    fprintf(stdout, "Program (id = %d) info log: %s\n", program, info_log);
    free(info_log);
    info_log = NULL;
}

// -----------------------------------------------------------------------------
GLA_LINKAGE void gla_print_shader_info_log(GLuint shader)
{
    GLint info_log_length = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_log_length);
    if (info_log_length <= 0) {
        fprintf(stdout, "Shader (id = %d) info log: <empty>\n", shader);
        return;
    }

    GLchar *info_log = malloc(info_log_length);
    if (!info_log) {
        fprintf(stderr, "Error: Shader (id = %d) info log printing: "
                        "Unable to allocate memory for the info log\n", shader);
        return;
    }
    glGetShaderInfoLog(shader, info_log_length, NULL, info_log);
    fprintf(stdout, "Shader (id = %d) info log: %s\n", shader, info_log);
    free(info_log);
    info_log = NULL;
}

// -----------------------------------------------------------------------------
GLA_LINKAGE GLchar *gla_read_text_file(const GLchar *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: File (\"%s\") handling: "
                        "Unable to open file\n", filename);
        return NULL;
    }

    const size_t buffer_size = 4096;
    char *buffer = malloc(buffer_size);
    if (!buffer) {
        fprintf(stderr, "Error: File (\"%s\") handling: "
                        "Unable to allocate memory for the reading buffer\n",
                        filename);
        return NULL;
    }

    size_t out_size = 2 * buffer_size;
    char *out = malloc(out_size + 1); // + '\0'
    if (!out) {
        free(buffer);
        buffer = NULL;
        fprintf(stderr, "Error: File (\"%s\") handling: "
                        "Unable to allocate memory for the source buffer\n",
                        filename);
        return NULL;
    }

    size_t num_read_total = 0;
    size_t num_read_step = 0;
    while ((num_read_step = fread(buffer, 1, buffer_size, file)) > 0) {
        // Make sure that there is enough space for storing the read data
        if (num_read_total >= out_size) {
            out_size *= 2;
            out = realloc(out, out_size + 1); // + '\0'
            if (!out) {
                free(buffer);
                buffer = NULL;
                fprintf(stderr, "Error: File (\"%s\") handling: "
                                "Unable to re-allocate memory for the source "
                                "buffer\n", filename);
                return NULL;
            }
        }

        out += num_read_total;
        memcpy(out, buffer, num_read_step);
        out -= num_read_total;

        num_read_total += num_read_step;
    }

    out[num_read_total] = '\0';
    free(buffer);
    buffer = NULL;

    if (fclose(file) == EOF) {
        free(out);
        out = NULL;
        fprintf(stderr, "Error: File (\"%s\") handling: "
                        "Unable to close file\n", filename);
        return NULL;
    }

    return out;
}

#endif // GLA_IMPLEMENTATION
