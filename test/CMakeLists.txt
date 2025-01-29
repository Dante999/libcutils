cmake_minimum_required(VERSION 3.16)

project(libcutils_test)

add_executable(${PROJECT_NAME}
        main.c
        test_result.c
        test_string_view.c
        test_util_makros.c
)

target_link_libraries(${PROJECT_NAME} PRIVATE libcutils)

