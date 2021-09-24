//
// Created by Thaumy on 2021/9/18.
//
#include <iostream>
#include <string>
#include <yparser.h>
#include <easyio.h>
#include "../../fn/fn.hpp"


using namespace std;
using namespace easyio;
using namespace yparser;

//串行解析计时测试
namespace test3 {
    int run() {
        auto path = R"(../test/test3/input.yml)";
        auto yml = read(path);
        auto parsed = YmlRaw(yml, parser::lazyParserMT).parse();
        return parsed.empty();
    }
}