//
// Created by Thaumy on 2021/9/18.
//

#include <iostream>
#include <string>
#include <yparser.h>
#include <easyio.h>
#include "io_yml_string.hpp"


using namespace std;
using namespace easyio;
using namespace yparser;

void format_test() {
    auto yml = get_yml_string();
    auto formatted = YmlRaw(yml, parser::lazyParser).toString();
    cout << "format_final:" << endl;
    cout << formatted;
}