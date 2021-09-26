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

//并发解析计时测试
namespace test5 {
    int run() {
        auto path = R"(../test/test5/input.yml)";
        auto yml = read(path);
        auto parsed = YmlRaw(yml, parser::lazyParser).parse();
        return parsed.empty();
    }
}