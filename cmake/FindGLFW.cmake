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

include(FindPackageHandleStandardArgs)
set(GLFW_FOUND FALSE)

# Search for the include directory
find_path(GLFW_INCLUDE_DIR
    GLFW/glfw3.h
    ${PROJECT_SOURCE_DIR}/deps/include
)
if(GLFW_INCLUDE_DIR)
    set(GLFW_FOUND TRUE)
endif()

# Narrow the search for the library file down, i.e.,
# look up operating system and compiler
if(WIN32)
    set(OS windows)
    if(MSVC)
        if(MSVC14)
            set(MSVC_VERSION msvc14)
        endif()
        if(MSVC12)
            set(MSVC_VERSION msvc12)
        endif()

        set(COMPILER ${MSVC_VERSION})
        set(SHARED_LIB_NAME glfw3dll.lib)
        set(STATIC_LIB_NAME glfw3.lib)
    endif()
    if(MINGW)
        set(COMPILER mingw)
        set(SHARED_LIB_NAME glfw3dll.a)
        set(STATIC_LIB_NAME libglfw3.a)
    endif()
else()
    # Apple and Linux
    if("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU" OR
        "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        set(COMPILER gcc)
    elseif(${CMAKE_C_COMPILER_ID} MATCHES "Clang" OR
        ${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
        set(COMPILER clang)
    endif()
    set(STATIC_LIB_NAME libglfw3.a)

    if(APPLE)
        set(OS macosx)
        set(SHARED_LIB_NAME libglfw.3.dylib)
    else()
        set(OS linux)
        set(SHARED_LIB_NAME libglfw.so.3)
    endif()
endif()

# Default to the shared version...
# ...if both versions have been requested
if(GLFW_FIND_REQUIRED_shared AND GLFW_FIND_REQUIRED_static)
    set(MSG "Shared and static versions have been requested at the same time. "
            "The shared version is the default."
    )
    message(WARNING ${MSG})
    list(REMOVE_ITEM GLFW_FIND_COMPONENTS static)
    unset(GLFW_FIND_REQUIRED_static)
endif()
# ...if no version has been requested
if(NOT GLFW_FIND_COMPONENTS)
    set(MSG "No version (shared or static) has been requested. "
            "The shared version is the default."
    )
    message(WARNING ${MSG})
    list(APPEND GLFW_FIND_COMPONENTS shared)
    set(GLFW_FIND_REQUIRED_shared TRUE)
endif()

# Search the shared version of the library
if(GLFW_FIND_REQUIRED_shared)
    if(WIN32)
        find_package(OpenGL REQUIRED)
        set(GLFW_opengl_LIBRARY ${OPENGL_gl_LIBRARY})
    endif()

    find_library(GLFW_glfw_SHARED_LIBRARY
        ${SHARED_LIB_NAME}
        ${PROJECT_SOURCE_DIR}/deps/lib/GLFW/x64/${OS}/${COMPILER}
    )
    find_package_handle_standard_args(GLFW_glfw_SHARED
        GLFW_INCLUDE_DIR
        GLFW_glfw_SHARED_LIBRARY
    )
    if(GLFW_glfw_SHARED_FOUND)
        set(GLFW_INCLUDE_DIRS ${GLFW_INCLUDE_DIR})
        set(GLFW_LIBRARIES
            ${GLFW_glfw_SHARED_LIBRARY}
            ${GLFW_opengl_LIBRARY}
        )
        set(GLFW_FOUND TRUE)
    endif()
    list(REMOVE_ITEM GLFW_FIND_COMPONENTS shared)
    unset(GLFW_FIND_REQUIRED_shared)
    mark_as_advanced(
        GLFW_INCLUDE_DIR
        GLFW_glfw_SHARED_LIBRARY
    )
endif()

# Search the static version of the library
if(GLFW_FIND_REQUIRED_static)
    if(WIN32)
        find_package(OpenGL REQUIRED)
        set(GLFW_opengl_LIBRARY ${OPENGL_gl_LIBRARY})
    else()
        if(APPLE)
            set(GLFW_cocoa_LIBRARY "-framework Cocoa"
                CACHE STRING "Cocoa framework for Mac OS X"
            )
            set(GLFW_io_kit_LIBRARY "-framework IOKit"
                CACHE STRING "IOKit framework for Mac OS X"
            )
            set(GLFW_core_video_LIBRARY "-framework CoreVideo"
                CACHE STRING "CoreVideo framework for Mac OS X"
            )
        else()
            # GLFW needs more libraries when statically linked
            # X11 libraries
            find_package(X11 REQUIRED)
            list(APPEND GLFW_x11_LIBRARY
                X11
                ${X11_Xcursor_LIB}
                ${X11_Xinerama_LIB}
                ${X11_Xrandr_LIB}
                ${X11_Xxf86vm_LIB}
                Xi
            )
            # Threads library
            find_package(Threads REQUIRED)
            set(GLFW_threads_LIBRARY ${CMAKE_THREAD_LIBS_INIT})
        endif()
    endif()

    find_library(GLFW_glfw_STATIC_LIBRARY
        ${STATIC_LIB_NAME}
        ${PROJECT_SOURCE_DIR}/deps/lib/GLFW/x64/${OS}/${COMPILER}
    )
    find_package_handle_standard_args(GLFW_glfw_STATIC
        GLFW_INCLUDE_DIR
        GLFW_glfw_STATIC_LIBRARY
    )
    if(GLFW_glfw_STATIC_FOUND)
        set(GLFW_INCLUDE_DIRS ${GLFW_INCLUDE_DIR})
        set(GLFW_LIBRARIES
            ${GLFW_glfw_STATIC_LIBRARY}
            ${GLFW_cocoa_LIBRARY}
            ${GLFW_io_kit_LIBRARY}
            ${GLFW_core_video_LIBRARY}
            ${GLFW_x11_LIBRARY}
            ${GLFW_threads_LIBRARY}
        )
        set(GLFW_FOUND TRUE)
    endif()
    list(REMOVE_ITEM GLFW_FIND_COMPONENTS static)
    unset(GLFW_FIND_REQUIRED_static)
    mark_as_advanced(
        GLFW_INCLUDE_DIR
        GLFW_glfw_STATIC_LIBRARY
    )
endif()
