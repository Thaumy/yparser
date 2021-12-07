cmake_minimum_required(VERSION 3.17)
project(include)

set(CMAKE_CXX_STANDARD 14)

set(LIBRARY_OUTPUT_PATH ../lib)

set(h1 include/yparser.h)
set(h2 include/globalheaders.h)
set(headers ${h1} ${h2})

set(f1 include/util/util.h include/util/util.cpp)
set(f2 include/type/YmlRaw.h include/type/YmlRaw.cpp)
set(f3 include/type/derived/YmlMap.h include/type/derived/impl/YmlMap.cpp)
set(f4 include/type/derived/YmlList.h include/type/derived/impl/YmlList.cpp)
set(f5 include/type/derived/YmlScalar.h include/type/derived/impl/YmlScalar.cpp)
set(f6 include/type/derived/YmlRoot.h include/type/derived/impl/YmlRoot.cpp)
set(f7 include/parser/parser.h include/parser/parser.cpp)
set(functions ${f1} ${f2} ${f3} ${f4} ${f5} ${f6} ${f7})

set(e1 include/exception/yparser_error.h include/exception/yparser_error.cpp)
set(e2 include/exception/derived/list_key_parse_err.hpp include/exception/derived/list_value_parse_err.hpp)
set(e3 include/exception/derived/map_key_parse_err.hpp include/exception/derived/map_value_parse_err.hpp)
set(e4 include/exception/derived/scalar_key_parse_err.hpp include/exception/derived/scalar_value_parse_err.hpp)
set(e5 include/exception/derived/unexpected_type_err.hpp)
set(e6 include/exception/derived/unknown_type_err.hpp)
set(exceptions ${e1} ${e2} ${e3} ${e4} ${e5} ${e6})

set(i1 include/interface/interface.h)
set(i2 include/interface/com/IKeyValueTangible.hpp)
set(i3 include/interface/com/IHashable.hpp)
set(i4 include/interface/com/ISerializable.hpp)
set(i5 include/interface/com/IStreamable.hpp)
set(i6 include/interface/com/IStringable.hpp)
set(interfaces ${i1} ${i2} ${i3} ${i4} ${i5} ${i6})

set(coms ${headers} ${functions} ${exceptions} ${interfaces})

# easyio
link_directories(../easyio/lib)
include_directories(../easyio/include)
link_libraries(easyio)
# Boost
link_directories(C:/Boost/lib)
include_directories(C:/Boost/include/boost-1_77)
link_libraries(${Boost_LIBRARIES})
# OpenSSL
link_directories(D:/app/OpenSSL-Win64/lib)
include_directories(D:/app/OpenSSL-Win64/include)
link_libraries(openssl libcrypto libssl)

add_library(yparser STATIC ${coms})
