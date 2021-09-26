//
// Created by Thaumy on 2021/9/24.
//

#ifndef DEMO_BLOB_GENERATOR_HPP
#define DEMO_BLOB_GENERATOR_HPP

#include <iostream>
#include <string>
#include <yparser.h>
#include <easyio.h>
#include "io_yml_string.hpp"


using namespace std;
using namespace easyio;

void blob_generator(int len) {
    ostringstream os;
    const auto base = 100000000;

    for (int i = 0; i < len; i += 3) {
        os << base + i + 1 << ":" << R"(
  stu1:
    first_name: Thaumy
    last_name: Cheng
    sex: male
    phone: 1234567890
    hobby:
      - coding
      - read book
      - fishing
  stu2:
    first_name: Alice
    last_name: Miyabi
    sex: female
    phone: 1527561890
    hobby:
      - small talk
      - sleeping
  stu3:
    first_name: Tim
    last_name: Cook
    sex: male
    phone: 1136569821
    hobby:
      - #This hobby can be broken down
        sell_things:
          - iphone
          - mac
          - etc
      - clear inventory
)";
    }
    set_yml_string(os.str());
}

#endif //DEMO_BLOB_GENERATOR_HPP
