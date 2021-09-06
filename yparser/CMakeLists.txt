cmake_minimum_required(VERSION 3.17)
project(include)

set(CMAKE_CXX_STANDARD 14)

set(root include)

set(f1 ${root}/yparser.h)
set(f2 ${root}/globalheaders.h)
set(f3 ${root}/util/util.h ${root}/util/util.cpp)
set(f4 ${root}/interface/interface.hpp)
set(f5 ${root}/type/YmlRaw.h ${root}/type/YmlRaw.cpp)
set(f6 ${root}/type/derived/YmlMap.h ${root}/type/derived/YmlMap.cpp)
set(f7 ${root}/type/derived/YmlList.h ${root}/type/derived/YmlList.cpp)
set(f8 ${root}/type/derived/YmlScalar.h ${root}/type/derived/YmlScalar.cpp)
set(functions ${f1} ${f2} ${f3} ${f4} ${f5} ${f6} ${f7} ${f8})

set(ef ${root}/exception)
set(e1 ${ef}/yparser_error.h ${ef}/yparser_error.cpp)
set(e2 ${ef}/derived/list_key_parse_err.hpp ${ef}/derived/list_value_parse_err.hpp)
set(e3 ${ef}/derived/map_key_parse_err.hpp ${ef}/derived/map_value_parse_err.hpp)
set(e4 ${ef}/derived/scalar_key_parse_err.hpp ${ef}/derived/scalar_value_parse_err.hpp)
set(exceptions ${e1} ${e2} ${e3} ${e4})

set(coms ${functions} ${exceptions})

include_directories(../easyio)
link_directories(../easyio/cmake-build-debug)
include_directories(D:/app/OpenSSL-Win64/include)
link_directories(D:/app/OpenSSL-Win64/lib)

link_libraries(easyio)
link_libraries(openssl libcrypto libssl)

add_library(yparser ${coms})

