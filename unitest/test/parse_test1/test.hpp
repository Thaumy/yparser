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

string parse_test1() {
    auto path = R"(../test/parse_test1/input.yml)";
    auto yml = read(path);
    ostringstream os;
    auto parsed = YmlRaw(yml, parser::lazyParser).parse();

    recParse(os, parsed);

    return os.str();
}

string parse_test1_output() {
    auto path = R"(../test/parse_test1/output.txt)";
    return read(path);
}