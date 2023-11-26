# Information cmake
cmake_minimum_required(VERSION 3.0.2)


file(COPY ./bin DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# add executable and target libraries
add_executable(elfotest elfotest.c)

target_include_directories (elfotest PRIVATE
		../include/

)

file(GLOB_RECURSE SOURCES
        *.c
        ../sources/*.c
)

target_sources(elfotest PRIVATE
		${SOURCES}
)