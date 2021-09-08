//
// Created by Thaumy on 2021/9/8.
//

#include "parser.h"

#define Self parser
#define YmlRaw yparser::YmlRaw


vector<YmlRaw> Self::lazyParser(const string &yml) {
    //(?:^|\n)(\w+:(?: .+|\n)(?:(?:  )+.+\n*)*)(?=\n|$)
    auto results = util::reg::multiSearch//此表达式不应该匹配得到每个节点末的\n
            (yml, R"(^\w+:[\n ](((  )+[^\n]+\n*)+(?=\n|$)|[^\n]+))");//perl syntax

    vector<YmlRaw> arr;

    for (const auto &el:results) {
        if (YmlRaw::isMap(el))
            arr.emplace_back(YmlRaw(el, YmlRaw::Type::mapping));
        else if (YmlRaw::isList(el))
            arr.emplace_back(YmlRaw(el, YmlRaw::Type::list));
        else if (YmlRaw::isScalar(el))
            arr.emplace_back(YmlRaw(el, YmlRaw::Type::scalar));
        else//is text
            arr.emplace_back(YmlRaw(el, YmlRaw::Type::text));
    }

    return vector<YmlRaw>(arr);
}

/*
vector<YmlRaw> Self::greedyParser(const string &yml) {
    //(?:^|\n)(\w+:(?: .+|\n)(?:(?:  )+.+\n*)*)(?=\n|$)
    auto results = util::reg::multiSearch//此表达式不应该匹配得到每个节点末的\n
            (yml, R"(^\w+:[\n ](((  )+[^\n]+\n*)+(?=\n|$)|[^\n]+))");//perl syntax

    vector<YmlRaw> arr;

    for (const auto &el:results) {
        if (YmlRaw::isMap(el)) {
            auto map_el = YmlMap::with(YmlRaw(el, YmlRaw::Type::mapping));
            arr.emplace_back(map_el);
        } else if (YmlRaw::isList(el)) {
            auto map_list = YmlList::with(YmlRaw(el, YmlRaw::Type::list));
            arr.emplace_back(map_list);
        } else if (YmlRaw::isScalar(el)) {
            auto map_scalar = YmlScalar::with(YmlRaw(el, YmlRaw::Type::scalar));
            arr.emplace_back(map_scalar);
        } else {//is text
            arr.emplace_back(YmlRaw(el, YmlRaw::Type::text));
        }
    }
    return vector<YmlRaw>(arr);
}*/
