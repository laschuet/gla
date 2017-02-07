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

cmake_minimum_required(VERSION 2.6)
project(GLA)

set(CMAKE_MODULE_PATH ${GLA_SOURCE_DIR}/cmake)

option(GLA_BUILD_EXAMPLES "Build GLA examples" ON)
option(GLA_EXAMPLES_DEPS_GLFW_USE_STATIC
       "Use the static version of the GLFW library when building GLA examples"
       ON
)

if(NOT GLA_BUILD_EXAMPLES)
    set(MSG "GLA is a header only library, i.e., there is no need to build it. "
            "Enable the option GLA_BUILD_EXAMPLES to build the examples. "
            "Nothing can be built when using this configuration."
    )
    message(STATUS ${MSG})
endif()

add_subdirectory(examples)
