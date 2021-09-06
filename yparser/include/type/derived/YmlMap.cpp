//
// Created by Thaumy on 2021/9/1.
//

#include "YmlMap.h"

#define regSS util::reg::singleSearch
#define regMS util::reg::multiSearch

#define Self yparser::YmlMap


Self::YmlMap(const string &yml) : YmlRaw(yml) {
    {//初始化key
        //regSS(yml, R"((?:^|\n)(\w+):(?: .+|\n)(?:(?:  )+.+\n*)*)", 1);
        auto result = regSS(yml, R"(\w+(?=:\n  \w))");//perl syntax
        if (!result.empty())
            this->setKey(result);
        else//无法解析key时报错
            throw map_key_parse_err
                    ("error occurred when parsing this:\n" + yml);
    }
    {//初始化value
        //(?:^|\n)\w+:(?: .+|\n)((?:(?:  )+.+\n*)*)
        auto result = regSS(yml, R"(\w+:\n(.+))", 1);//perl syntax
        if (!result.empty()) {
            util::yml::decIndentation(result);//对结果减少缩进
            this->setValue(result);
        } else//无法解析value时报错
            throw map_value_parse_err
                    ("error occurred when parsing this:\n" + yml);
    }
    {
        //(?:^|\n)(\w+:(?: .+|\n)(?:(?:  )+.+\n*)*)(?=\n|$)
        //(?:^|\n)(\w+):(?: .+|\n)(?:(?:  )+.+\n*)*(?=\n|$)
        auto keys = regMS(this->getValue(), R"(^\w+)");//perl syntax
        auto raws = regMS(this->getValue(), R"(^\w+:[\n ](((  )+[^\n]+\n*)+(?=\n)|[^\n]+))");//perl syntax
        if (keys.size() != raws.size() || keys.empty())
            //无法解析value到std::map容器时报错
            throw map_value_parse_err
                    ("error occurred when parsing this into std::map:\n" + yml);
        else
            for (int i = 0; i < keys.size(); ++i) {
                auto el_key = keys.at(i);
                auto el_raw = raws.at(i);
                auto el = pair<string, YmlRaw>(el_key, YmlRaw(el_raw));
                elements.insert(el);
            }
    }
}

Self *Self::with(const YmlRaw *ymlRaw) {//TODO 记得改引用
    auto raw = ymlRaw->toString();
    if (ymlRaw->isMap())
        return new YmlMap(raw);
    else
        throw bad_cast();
}
