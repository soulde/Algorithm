cmake_minimum_required(VERSION 3.17)
project(algorithm)

set(CMAKE_CXX_STANDARD 14)
include_directories(Sort)
add_executable(algorithm main.cpp Sort/Sort.h)