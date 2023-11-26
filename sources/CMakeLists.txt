# Information cmake
cmake_minimum_required(VERSION 3.0.2)

file(GLOB_RECURSE SOURCES
    *.c
)

add_library(elfo SHARED ${SOURCES})

target_include_directories (elfo PRIVATE
    ../include/
)

