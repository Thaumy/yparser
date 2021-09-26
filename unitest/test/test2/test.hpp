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

//此用例测试示例文本2的正确解析
//使用lazyParser
namespace test2 {
    string run() {
        auto path = R"(../test/test2/input.yml)";
        auto yml = read(path);
        ostringstream os;
        auto parsed = YmlRaw(yml, parser::lazyParser).parse();

        recParse(os, parsed);

        return os.str();
    }

    string output() {
        auto path = R"(../test/test2/output.txt)";
        return read(path);
    }
}