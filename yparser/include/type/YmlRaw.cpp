//
// Created by Thaumy on 2021/9/1.
//

#include "YmlRaw.h"

#define regSS util::regexSingleSearch
#define regMS util::regexMultiSearch

#define Self yparser::YmlRaw


string Self::SHA256() const {
    return util::stringToSHA256(this->raw);
}

string Self::toString() const {
    return string(this->raw);
}

Self::YmlRaw(string yml) {//默认用户输入需要格式化，只有此构造才会调用格式化函数流水线
    this->type = text;//默认为文本类型

    using namespace util;
    function<void(string &)> pipeline[] =//格式化函数流水线
            {delAnnotation,//删除注释
             delBlankLine,//清除空行
             delLineEndSpace,//清除行尾空格
             fixIndentation};//修复错误缩进
    for (const auto &f:pipeline)
        f(yml);//按照流水线处理yml

    this->raw = std::move(yml);//右值引用以提升性能
}

Self::YmlRaw(string yml, const Type type) {//该构造不会使用格式化函数流水线，因为它一定由格式化的yml构造
    this->type = type;
    this->raw = std::move(yml);//右值引用以提升性能
}

vector<Self *> Self::parse(const bool &lazy) const {
    auto results = regMS//此表达式不会匹配得到每个节点末的\n
            (this->raw, R"((?:^|\n)(\w+:(?: .+|\n)(?:(?:  )+.+\n*)*)(?=\n|$))", 1);

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
    regex expr(R"(^\w+:\n(  )+\w+:)");
    return regex_search(yml, expr, mode);
}

bool Self::isList(const string &yml) {
    regex expr(R"(^\w+:\n  -)");
    return regex_search(yml, expr, mode);
}

bool Self::isScalar(const string &yml) {
    regex expr(R"(^\w+: .+)");
    return regex_search(yml, expr, mode);
}
