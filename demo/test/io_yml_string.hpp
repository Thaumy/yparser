//
// Created by Thaumy on 2021/9/25.
//

#ifndef DEMO_IO_YML_STRING_HPP
#define DEMO_IO_YML_STRING_HPP

#include <iostream>
#include <string>
#include <yparser.h>
#include <easyio.h>


using namespace std;
using namespace easyio;
using namespace yparser;

auto path = R"(../yml/example.yml)";

string get_yml_string() {
    auto yml = read(path);
    return yml;
}

void set_yml_string(const string &str) {
    auto yml = read(path);
    write(str, path);
}

#endif //DEMO_IO_YML_STRING_HPP
