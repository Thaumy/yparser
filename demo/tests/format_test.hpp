//
// Created by Thaumy on 2021/9/18.
//

#include <iostream>
#include <string>
#include <yparser.h>
#include <easyio.h>


using namespace std;
using namespace easyio;
using namespace yparser;

void format_test() {
    auto path = R"(../configs/config.yml)";;;;
    auto yml = *read(path);
    auto formatted = YmlRaw(yml, parser::lazyParser).toString();
    cout << "format_final:" << endl;;
    cout << formatted;
}