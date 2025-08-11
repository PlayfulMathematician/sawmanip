cmake_minimum_required(VERSION 3.31)
project(sawmanip C)

set(CMAKE_C_STANDARD 11)

# Tell compiler where to find headers
include_directories(include)

add_executable(sawmanip
        source/main.c
        source/saw.c
        source/random.c
        include/random.h
        include/saw.h

)
