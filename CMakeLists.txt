cmake_minimum_required(VERSION 3.16)

project(libcutils C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Wpedantic -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(${PROJECT_NAME}
        src/result.c
        src/string_view.c
        src/arg_parser.c
        src/result.c
)

target_include_directories(${PROJECT_NAME} PUBLIC ./include)

add_subdirectory(test)
