cmake_minimum_required(VERSION 3.17)
project(include)

set(CMAKE_CXX_STANDARD 14)


set(p1 include/yparser.h)
set(p2 include/util/util.h include/util/util.cpp)
set(p3 include/type/YmlRaw.h include/type/YmlRaw.cpp)
set(p4 include/type/derived/YmlMap.h include/type/derived/YmlMap.cpp)
set(p5 include/type/derived/YmlList.h include/type/derived/YmlList.cpp)
set(p6 include/type/derived/YmlScalar.h include/type/derived/YmlScalar.cpp)
set(ps ${p1} ${p2} ${p3} ${p4} ${p5} ${p6} include/interface/interface.cpp include/interface/interface.h include/globalheaders.h)

include_directories(../easyio)
link_directories(../easyio/cmake-build-debug)
include_directories(D:/app/OpenSSL-Win64/include)
link_directories(D:/app/OpenSSL-Win64/lib)

link_libraries(easyio)
link_libraries(openssl libcrypto libssl)

add_library(yparser ${ps})

