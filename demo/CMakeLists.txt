cmake_minimum_required(VERSION 3.17)
project(demo)

set(CMAKE_CXX_STANDARD 14)


include_directories(../yparser/include)
link_directories(../yparser/cmake-build-debug)
include_directories(../easyio)
link_directories(../easyio/cmake-build-debug)
include_directories(D:/app/OpenSSL-Win64/include)
link_directories(D:/app/OpenSSL-Win64/lib)
include_directories(C:/Boost/include/boost-1_77)
link_directories(C:/Boost/lib)

link_libraries(yparser)
link_libraries(easyio)
link_libraries(openssl libssl libcrypto)

add_executable(demo main.cpp)

target_link_libraries(demo yparser easyio openssl libssl libcrypto)
