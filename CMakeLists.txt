# cmake_minimum_required(VERSION <specify CMake version here>)
project(compile C)

set(CMAKE_C_STANDARD 99)

add_executable(compile main.c cifa.cpp Token.cpp asd.c)