cmake_minimum_required(VERSION 3.17)
project(easyio)

set(CMAKE_CXX_STANDARD 14)

set(LIBRARY_OUTPUT_PATH ../lib)

add_library(easyio STATIC include/easyio.h include/easyio.cpp)