cmake_minimum_required(VERSION 3.17)
project(include)

set(CMAKE_CXX_STANDARD 14)

set(root include)

set(f1 include/yparser.h)
set(f2 include/globalheaders.h)
set(f3 include/util/util.h include/util/util.cpp)
set(f4 include/interface/interface.h)
set(f5 include/type/YmlRaw.h include/type/YmlRaw.cpp)
set(f6 include/type/derived/YmlMap.h include/type/derived/YmlMap.cpp)
set(f7 include/type/derived/YmlList.h include/type/derived/YmlList.cpp)
set(f8 include/type/derived/YmlScalar.h include/type/derived/YmlScalar.cpp)
set(f9 include/type/derived/YmlRoot.h include/type/derived/YmlRoot.cpp)
set(f10 include/parser/parser.h include/parser/parser.cpp)
set(functions ${f1} ${f2} ${f3} ${f4} ${f5} ${f6} ${f7} ${f8} ${f9} ${f10})

set(ef include/exception)
set(e1 ${ef}/yparser_error.h ${ef}/yparser_error.cpp)
set(e2 ${ef}/derived/list_key_parse_err.hpp ${ef}/derived/list_value_parse_err.hpp)
set(e3 ${ef}/derived/map_key_parse_err.hpp ${ef}/derived/map_value_parse_err.hpp)
set(e4 ${ef}/derived/scalar_key_parse_err.hpp ${ef}/derived/scalar_value_parse_err.hpp)
set(e5 ${ef}/derived/unknown_type_err.hpp)
set(e6 ${ef}/derived/unexpected_type_err.hpp)
set(exceptions ${e1} ${e2} ${e3} ${e4} ${e5} ${e6})

set(coms ${functions} ${exceptions} include/interface/com/IKeyValueTangible.hpp include/interface/com/IHashable.hpp include/interface/com/IStringable.hpp include/interface/com/ISerializable.hpp include/interface/com/IStreamable.hpp)

include_directories(../easyio)
link_directories(../easyio/cmake-build-debug)
include_directories(D:/app/OpenSSL-Win64/include)
link_directories(D:/app/OpenSSL-Win64/lib)
include_directories(C:/Boost/include/boost-1_77)
link_directories(C:/Boost/lib)

link_libraries(easyio)
link_libraries(openssl libcrypto libssl)

add_library(yparser STATIC ${coms})
