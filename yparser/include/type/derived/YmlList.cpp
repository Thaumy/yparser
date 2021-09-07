//
// Created by Thaumy on 2021/9/1.
//

#include "YmlList.h"

#define regSS util::reg::singleSearch
#define regMS util::reg::multiSearch

#define Self yparser::YmlList


Self::YmlList() : YmlRaw(
        "zero parameter constructor of YmlList",//标识到yml方便debug
        list) {}

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
        auto result = regSS
                (yml, R"((?:(?:  )+(?:- .+|\w+:.*|-)\n*)+(?=\n|$))");//perl syntax
        if (!result.empty()) {
            util::yml::decIndentation(result);
            this->setValue(result);
        } else//无法解析value时报错
            throw list_value_parse_err
                    ("error occurred when parsing this:\n" + yml);
    }
    {//初始化elements
        //(-[ \n]((?:[^\n]+\n*)+?|[^\n]+)(?=-|$))
        auto result = regMS
                (this->getValue(), R"(^- ?([^\n]+|\n(?:(?:  )+[^\n]+\n*)+(?=\n|$)))", 1);//perl syntax
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

string Self::serialize() {
    ostringstream serialized;//提高拼接效率
    serialized << getKey() << ":\n";

    using namespace util::yml;
    for (const auto &el:elements) {
        auto el_string = el.toString();
        if (isSingleLine(el_string))
            serialized << "  - " << el_string << "\n";//最后会产生空行
        else {//对非单行文本缩进两次
            incIndentation(el_string);
            incIndentation(el_string);
            serialized << "  -\n"
                       << el_string << "\n";//最后会产生空行
        }
    }

    raw = serialized.str();
    formatPipeline(raw);
    return raw;
}

void Self::setKey(const string &newKey) {
    IKeyValueTangible::setKey(newKey);
}

void Self::addElement(const YmlRaw &element) {
    this->elements.emplace_back(element);
}

vector<yparser::YmlRaw> Self::getElements() {
    return elements;
}

Self *Self::with(const YmlRaw *ymlRaw) {
    auto raw = ymlRaw->toString();
    if (ymlRaw->isList())
        return new YmlList(raw);
    else
        throw bad_cast();
}
