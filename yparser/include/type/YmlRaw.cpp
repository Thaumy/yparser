//
// Created by Thaumy on 2021/9/1.
//

#include "YmlRaw.h"

#define regSS util::reg::singleSearch
#define regMS util::reg::multiSearch

#define Self yparser::YmlRaw


using namespace boost;

string Self::SHA256() const {
    return util::stringToSHA256(this->raw);
}

string Self::toString() const {
    return string(this->raw);
}

Self::YmlRaw(string yml) {//默认用户输入需要格式化，只有此构造才会调用格式化函数流水线
    this->type = text;//默认为文本类型
    util::yml::formatPipeline(yml);//格式化
    this->raw = std::move(yml);//右值引用以提升性能
}

Self::YmlRaw(string yml, const Type type) {//该构造不会使用格式化函数流水线，因为它一定由格式化的yml构造
    this->type = type;
    this->raw = std::move(yml);//右值引用以提升性能
}

vector<Self *> Self::parse(const bool &lazy) const {
    //(?:^|\n)(\w+:(?: .+|\n)(?:(?:  )+.+\n*)*)(?=\n|$)
    auto results = regMS//此表达式不应该匹配得到每个节点末的\n
            (this->raw, R"(^\w+:[\n ](((  )+[^\n]+\n*)+(?=\n|$)|[^\n]+))");//perl syntax

    vector<Self *> arr;

    for (const auto &result:results) {
        if (isMap(result))
            arr.emplace_back(new Self(result, mapping));
        else if (isList(result))
            arr.emplace_back(new Self(result, list));
        else if (isScalar(result))
            arr.emplace_back(new Self(result, scalar));
        else
            arr.emplace_back(new Self(result, text));
    }

    return vector<YmlRaw *>(arr);
}

#define mode regex_constants::format_first_only//只搜索第一个匹配项

bool Self::isMap() const {
    return this->type == mapping;
}

bool Self::isList() const {
    return this->type == list;
}

bool Self::isScalar() const {
    return this->type == scalar;
}

bool Self::isText() const {
    return this->type == text;
}

//privates:

bool Self::isMap(const string &yml) {
    //^\w+:\n(  )+\w+:
    regex expr(R"(^\w+:\n  \w)");//perl syntax
    return regex_search(yml, expr, mode);
}

bool Self::isList(const string &yml) {
    regex expr(R"(^\w+:\n  -)");
    return regex_search(yml, expr, mode);
}

bool Self::isScalar(const string &yml) {
    //^\w+: .+
    regex expr(R"(^\w+: [^\n])");//perl syntax
    return regex_search(yml, expr, mode);
}
