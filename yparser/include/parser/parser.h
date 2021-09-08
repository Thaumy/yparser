//
// Created by Thaumy on 2021/9/8.
//

#ifndef INCLUDE_PARSER_H
#define INCLUDE_PARSER_H

#include "../type/YmlRaw.h"
#include "../type/derived/YmlMap.h"
#include "../type/derived/YmlList.h"
#include "../type/derived/YmlScalar.h"


using namespace yparser;

namespace parser {
    //惰性求值yml解析器，适用于层次化结构的单层解析
    vector<YmlRaw> lazyParser(const string &yml);

    //贪婪求值yml解析器，适用于层次化结构的递归式解析
    //vector<YmlRaw> greedyParser(const string &yml);
}

#endif //INCLUDE_PARSER_H
