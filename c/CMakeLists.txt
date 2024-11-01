cmake_minimum_required(VERSION 3.0)
project(beve_c)

set(CMAKE_C_STANDARD 11)

file(GLOB_RECURSE C_GEN_SOURCES
    src/generator/*.c
)

add_executable(${PROJECT_NAME}-gen
    ${C_GEN_SOURCES}
)
