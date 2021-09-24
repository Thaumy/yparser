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
    return this->raw;
}

Self::YmlRaw() {

}

//默认用户输入需要格式化，只有此构造才会调用格式化函数流水线
Self::YmlRaw(string yml,
             const function<vector<Self>(const string &)> &parser) {
    this->type = text;//默认为文本类型
    util::yml::formatPipeline(yml);//格式化
    this->raw = std::move(yml);//右值引用以提升性能
    this->parser = parser;//初始化解析器
}

//该构造不会使用格式化函数流水线，因为它一定由格式化的yml构造
Self::YmlRaw(string yml, const Type type,
             const function<vector<Self>(const string &)> &parser) {
    this->type = type;
    this->raw = std::move(yml);//右值引用以提升性能
    this->parser = parser;//初始化解析器
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

bool Self::isRoot() const {
    return this->type == root;
}

bool Self::isText() const {
    return this->type == text;
}

inline bool Self::isMap(const string &yml) {
    //^\w+:\n(  )+\w+:
    regex expr(R"(^\w+:\n  \w)");//perl syntax
    return regex_search(yml, expr, mode);
}

inline bool Self::isList(const string &yml) {
    regex expr(R"(^(\w+|):\n  -)");//为兼容无键列表，使用\w+|
    return regex_search(yml, expr, mode);
}

inline bool Self::isScalar(const string &yml) {
    //^\w+: .+
    regex expr(R"(^\w+: [^\n])");//perl syntax
    return regex_search(yml, expr, mode);
}

inline bool Self::isRoot(const string &yml) {
    auto results = util::reg::multiSearch//与parser用的表达式相同
            (yml, R"(^\w+:[\n ](((  )+[^\n]+\n*)+(?=\n|$)|[^\n]+))");//perl syntax
    //如果结果大于1的话就是聚合根（0为text类型情况，非聚合根）
    return results.size() > 1;
}

Self::Type Self::getType(const string &yml) {
    if (isMap(yml))
        return mapping;
    if (isList(yml))
        return list;
    if (isScalar(yml))
        return scalar;
    if (isRoot(yml))
        return root;
    return text;
}

vector<yparser::YmlRaw> Self::parse() const {
    return this->parser(this->raw);
}
