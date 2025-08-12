cmake_minimum_required(VERSION 3.31)
project(sawmanip C)

set(CMAKE_C_STANDARD 11)

add_executable(sawmanip
        source/main.c
        source/saw.c
        source/random.c
        source/utils.c
)

target_include_directories(sawmanip PRIVATE include)
