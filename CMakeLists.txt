cmake_minimum_required(VERSION 3.6)
project(snake)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c list.c list.h)
add_executable(snake ${SOURCE_FILES})