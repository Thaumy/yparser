//
// Created by Thaumy on 2021/9/1.
//

#include "YmlList.h"

#define regSS util::reg::singleSearch
#define regMS util::reg::multiSearch

#define Self yparser::YmlList


Self::YmlList(const string &yml) : YmlRaw(yml) {
    {//初始化key
        auto result = regSS(yml, R"((\w+):\n  -)", 1);
        if (!result.empty())
            this->setKey(result);
        else//无法解析key时报错
            throw list_key_parse_err
                    ("error occurred when parsing this:\n" + yml);
    }
    {//初始化value
        auto result = regSS(yml, R"((?:(?:  )+(?:- .+|\w+:.*|-)\n*)+(?=\n|$))");
        if (!result.empty()) {
            util::yml::decIndentation(result);
            this->setValue(result);
        } else//无法解析value时报错
            throw list_value_parse_err
                    ("error occurred when parsing this:\n" + yml);
    }
    {//初始化elements
        auto result = regMS(this->getValue(), R"(-[ \n]((?:[^\n]+\n*)+?|[^\n]+)(?=-|$))", 1);
        if (!result.empty()) {
            for (auto el:result) {
                util::yml::decIndentation(el);
                elements.emplace_back(YmlRaw(el));
            }
        } else//无法解析value到std::vector容器时
            throw list_value_parse_err
                    ("error occurred when parsing this into std::vector:\n" + yml);
    }
}

Self *Self::with(const YmlRaw *ymlRaw) {
    auto raw = ymlRaw->toString();
    if (ymlRaw->isList())
        return new YmlList(raw);
    else
        throw bad_cast();
}
