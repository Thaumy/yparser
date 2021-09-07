//
// Created by Thaumy on 2021/9/1.
//

#include "YmlList.h"

#define regSS util::regexSingleSearch
#define regMS util::regexMultiSearch

#define Self yparser::YmlList


Self::YmlList(const string &yml) : YmlRaw(yml) {
    {//初始化key
        auto result = regSS(yml, R"((\w+):\n  -)", 1);
        if (!result.empty())
            key = result;
        else
            throw "can't parse key";//无法解析key
    }
    {//初始化value
        auto result = regSS(yml, R"((?:(?:  )+(?:- .+|\w+:.*|-)\n*)+(?=\n|$))");
        if (!result.empty()) {
            util::decIndentation(result);
            value = result;
        } else
            throw "can't parse value";//无法解析value
    }
    {//初始化elements
        auto result = regMS(value, R"(-[ \n]((?:[^\n]+\n*)+?|[^\n]+)(?=-|$))", 1);
        for (auto el:result) {
            util::decIndentation(el);
            elements.emplace_back(YmlRaw(el));
        }
    }
}

Self *Self::with(const YmlRaw *ymlRaw) {
    auto raw = ymlRaw->toString();
    if (ymlRaw->isList())
        return new YmlList(raw);
    else
        throw bad_cast();
}
