//
// Created by Thaumy on 2021/9/1.
//

#include "YmlScalar.h"

#define regSS util::regexSingleSearch
#define regMS util::regexMultiSearch

#define Self yparser::YmlScalar


Self::YmlScalar(const string &yml) : YmlRaw(yml) {
    {//初始化key
        auto result = regSS(yml, R"((\w+): .+)", 1);
        if (!result.empty())
            key = result;
        else
            throw "can't parse key";//无法解析key
    }
    {//初始化value
        auto result = regSS(yml, R"(\w+: (.+))", 1);
        if (!result.empty()) {
            util::decIndentation(result);//对结果减少缩进
            value = result;
        } else
            throw "can't parse value";//无法解析value
    }
}

Self *Self::with(const YmlRaw *ymlRaw) {
    auto raw = ymlRaw->toString();
    if (ymlRaw->isScalar())
        return new YmlScalar(raw);
    else
        throw bad_cast();
}
