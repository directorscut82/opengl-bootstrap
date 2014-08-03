cmake_minimum_required(VERSION 2.8)
project(glxw C)

find_package(PythonInterp REQUIRED)


include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)


#- KHR

file(
    COPY ${CMAKE_CURRENT_SOURCE_DIR}/include/KHR/khrplatform.h
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/include/KHR
)


#- OpenGL

file(
    COPY ${CMAKE_CURRENT_SOURCE_DIR}/include/GL/glcorearb.h
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/include/GL
)

add_custom_command(
    OUTPUT
        ${CMAKE_CURRENT_BINARY_DIR}/src/glxw.c
        ${CMAKE_CURRENT_BINARY_DIR}/include/GLXW/glxw.h
    COMMAND
        ${PYTHON_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/glxw_gen.py
        --api opengl
        --generate
        --output ${CMAKE_CURRENT_BINARY_DIR}
    MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/glxw_gen.py
)

add_library(glxw STATIC ${CMAKE_CURRENT_BINARY_DIR}/src/glxw.c)
