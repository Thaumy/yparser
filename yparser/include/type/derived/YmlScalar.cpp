//
// Created by Thaumy on 2021/9/1.
//

#include "YmlScalar.h"

#define regSS util::reg::singleSearch
#define regMS util::reg::multiSearch

#define Self yparser::YmlScalar


Self::YmlScalar(const string &key, const string &value) :
        YmlRaw(key + ": " + value, scalar) {
    setKey(key);
    setValue(value);
}

Self::YmlScalar(const string &yml) : YmlRaw(yml, scalar) {
    {//初始化key
        //(\w+): .+
        auto result = regSS(yml, R"(^\w+)");//perl syntax
        if (!result.empty())
            this->setKey(result);
        else//无法解析key时报错
            throw scalar_key_parse_err
                    ("error occurred when parsing this:\n" + yml);
    }
    {//初始化value
        //\w+: (.+)
        auto result = regSS(yml, R"(^\w+: (.+))", 1);//perl syntax
        if (!result.empty()) {
            util::yml::decIndentation(result);//对结果减少缩进
            this->setValue(result);
        } else//无法解析value时报错
            throw scalar_value_parse_err
                    ("error occurred when parsing this:\n" + yml);
    }
}

string Self::serialize() {
    return getKey() + ": " + getValue();
}

Self Self::with(const YmlRaw &ymlRaw) {
    auto raw = ymlRaw.toString();
    if (ymlRaw.isScalar())
        return YmlScalar(raw);
    else
        throw bad_cast();
}
