//
// Created by Thaumy on 2021/9/1.
//

#include "YmlMap.h"

#define regSS util::regexSingleSearch
#define regMS util::regexMultiSearch

#define Self yparser::YmlMap


Self::YmlMap(const string &yml) : YmlRaw(yml) {
    {//初始化key
        auto result = regSS(yml, R"((?:^|\n)(\w+):(?: .+|\n)(?:(?:  )+.+\n*)*)", 1);
        if (!result.empty())
            key = result;
        else
            throw "can't parse key";//无法解析key
    }
    {//初始化value
        auto result = regSS(yml, R"((?:^|\n)\w+:(?: .+|\n)((?:(?:  )+.+\n*)*))",1);
        if (!result.empty()) {
            util::decIndentation(result);//对结果减少缩进
            value = result;
        } else
            throw "can't parse value";//无法解析value
    }
    {
        auto keys = regMS(value, R"((?:^|\n)(\w+):(?: .+|\n)(?:(?:  )+.+\n*)*)", 1);
        auto raws = regMS(value, R"((?:^|\n)\w+:(?: .+|\n)(?:(?:  )+.+\n*)*)");
        if (keys.size() != raws.size() || keys.empty())
            throw "can't parse value into std::map";//无法解析value到std::map容器
        else
            for (int i = 0; i < keys.size(); ++i) {
                auto el_key = keys.at(i);
                auto el_raw = raws.at(i);
                auto el = pair<string, YmlRaw>(el_key, YmlRaw(el_raw));
                elements.insert(el);
            }
    }
}

Self *Self::with(const YmlRaw *ymlRaw) {
    auto raw = ymlRaw->toString();
    if (ymlRaw->isMap())
        return new YmlMap(raw);
    else
        throw bad_cast();
}
