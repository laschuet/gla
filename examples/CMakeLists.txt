# The MIT License (MIT)
#
# Copyright (c) 2015-present Lars Schütz
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

if(GLA_EXAMPLES_DEPS_GLFW_USE_STATIC)
    find_package(GLFW REQUIRED COMPONENTS static)
else()
    find_package(GLFW REQUIRED COMPONENTS shared)
    add_definitions(-DGLFW_DLL)
endif()

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

include_directories(${GLFW_INCLUDE_DIR}
                    ${GLA_SOURCE_DIR}/deps/include
                    ${GLA_SOURCE_DIR}
)

set(DEPS_SRC_GLAD ${GLA_SOURCE_DIR}/deps/include/glad.c)
list(APPEND DEPS_LIB_ALL ${GLFW_LIBRARIES})

if(UNIX AND NOT APPLE)
    list(APPEND DEPS_LIB_ALL ${CMAKE_DL_LIBS} m)
endif()

add_executable(cube WIN32 MACOSX_BUNDLE cube.c ${DEPS_SRC_GLAD})
target_link_libraries(cube ${DEPS_LIB_ALL})

if(MSVC)
    set_target_properties(cube PROPERTIES LINK_FLAGS "/ENTRY:mainCRTStartup")
endif()

set(FILES_SHADERS cube_vs.glsl cube_fs.glsl)

install(TARGETS cube DESTINATION ${CMAKE_INSTALL_PREFIX}/cube)
install(FILES ${FILES_SHADERS} DESTINATION ${CMAKE_INSTALL_PREFIX}/cube)
