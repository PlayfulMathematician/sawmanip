cmake_minimum_required(VERSION 3.31)
project(sawmanip C)

set(CMAKE_C_STANDARD 11)

# Tell compiler where to find headers
include_directories(include)

add_executable(sawmanip
        src/main.c
        src/saw.c
)
