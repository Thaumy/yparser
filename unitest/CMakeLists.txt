cmake_minimum_required(VERSION 3.20)
project(unitest)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib)
include_directories(googletest/include)

# yparser
link_directories(../yparser/lib)
include_directories(../yparser/include)
link_libraries(yparser)
# easyio
link_directories(../easyio/lib)
include_directories(../easyio/include)
link_libraries(easyio)
# OpenSSL
link_directories(D:/app/OpenSSL-Win64/lib)
include_directories(D:/app/OpenSSL-Win64/include)
link_libraries(openssl libssl libcrypto)
# Boost
link_directories(C:/Boost/lib)
include_directories(C:/Boost/include/boost-1_77)
link_libraries(${Boost_LIBRARIES})

file(GLOB all_tests test/*/*.hpp)
set(test_headers fn/fn.hpp ${all_tests})

add_executable(unitest main.cpp globalheaders.h ${test_headers})

target_link_libraries(unitest gtest gtest_main yparser easyio)