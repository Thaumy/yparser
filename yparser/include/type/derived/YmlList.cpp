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

Self::YmlList(const string &yml) : YmlRaw(yml, list) {
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
                if (isRoot(el)) {//只有在List的情况下才可能产生聚合根
                    YmlRoot root_el(el);
                    elements.emplace_back(root_el);
                } else
                    elements.emplace_back(YmlRaw(el, YmlRaw::getType(el)));
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

    auto result = serialized.str();
    delBlankLine(result);//删除空行
    return result;
}

Self Self::complie() {
    raw = serialize();
    return *this;
}

Self Self::with(const YmlRaw &ymlRaw) {
    auto raw = ymlRaw.toString();
    if (ymlRaw.isList())
        return YmlList(raw);
    else
        throw bad_cast();
}

void Self::setKey(const string &newKey) {
    IKeyValueTangible::setKey(newKey);
}

void Self::addElement(const YmlRaw &element) {
    //编译后添加到元素列表
    if (typeid(element) == typeid(YmlMap))
        elements.emplace_back(((YmlMap &&) element).complie());
    else if (typeid(element) == typeid(YmlList))
        elements.emplace_back(((YmlList &&) element).complie());
    else if (typeid(element) == typeid(YmlRoot))
        elements.emplace_back(((YmlRoot &&) element).complie());
    else if (typeid(element) == typeid(YmlScalar))
        elements.emplace_back(((YmlScalar &&) element));
    else//is text
        elements.emplace_back(YmlRaw(element));
}

vector<yparser::YmlRaw> Self::getElements() {
    return elements;
}
