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

    //lazyParser的多线程（Multithreading）版本，当一级Yaml超大型元素较多时适用
    //当一级Yaml元素较小且数量较少时，会因上下文开销较大而损失性能
    //除非解析时间令人难以接受，否则不要尝试使用此解析器
    vector<YmlRaw> lazyParserMT(const string &yml);

    //贪婪求值yml解析器，适用于层次化结构的递归式解析
    //vector<YmlRaw> greedyParser(const string &yml);
}

#endif //INCLUDE_PARSER_H
