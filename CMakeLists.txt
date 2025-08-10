cmake_minimum_required(VERSION 3.16)
project(cses)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Werror)

file(GLOB_RECURSE PROBLEM_SOURCES "${CMAKE_SOURCE_DIR}/problems/**/*.cpp")

foreach(SOURCE_FILE ${PROBLEM_SOURCES})
    get_filename_component(PROBLEM_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(${PROBLEM_NAME} ${SOURCE_FILE})
endforeach()

list(LENGTH PROBLEM_SOURCES NUM_PROBLEMS)
message(STATUS "Configured ${NUM_PROBLEMS} problems")
