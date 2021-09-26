cmake_minimum_required(VERSION 3.17)
project(demo)

set(CMAKE_CXX_STANDARD 14)

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

add_executable(demo main.cpp test/parse_test.hpp test/serialize_test1.hpp test/serialize_test2.hpp test/format_test.hpp test/blob_generator.hpp test/io_yml_string.hpp)

target_link_libraries(demo yparser easyio)
