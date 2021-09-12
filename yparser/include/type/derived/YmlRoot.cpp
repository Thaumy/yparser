//
// Created by Thaumy on 2021/9/7.
//

#include "YmlRoot.h"

#define Self yparser::YmlRoot


Self::YmlRoot() : YmlRaw(
        "zero parameter constructor of YmlRoot",//标识到yml方便debug
        root) {}

Self::YmlRoot(const string &yml) : YmlRaw(yml, root) {
    auto results = util::reg::multiSearch//与parser用的表达式相同
            (yml, R"(^\w+:[\n ](((  )+[^\n]+\n*)+(?=\n|$)|[^\n]+))");//perl syntax

    for (const auto &el: results) {
        if (YmlRaw::isMap(el))
            elements.emplace_back(YmlRaw(el, YmlRaw::Type::mapping));
        else if (YmlRaw::isList(el))
            elements.emplace_back(YmlRaw(el, YmlRaw::Type::list));
        else if (YmlRaw::isScalar(el))
            elements.emplace_back(YmlRaw(el, YmlRaw::Type::scalar));
        else//无法解析的元素类型，聚合根不能包含text或root
            throw unknown_type_err("unknown element type when parsing root:\n" + el);
    }
}

string Self::serialize() const {
    ostringstream serialized;//提高拼接效率

    for (const auto &el: elements) {
        serialized << el.toString() << "\n";//最后会产生空行
    }

    auto result = serialized.str();
    util::yml::delBlankLine(result);//删除空行
    return result;
}

Self Self::complie() {
    raw = serialize();
    return *this;
}

vector<yparser::YmlRaw> Self::getElements() {
    return elements;
}

void Self::add(const yparser::YmlRaw &element) {
    //编译后添加到元素列表
    if (typeid(element) == typeid(YmlMap))
        elements.emplace_back(((YmlMap &&) element).complie());
    else if (typeid(element) == typeid(YmlList))
        elements.emplace_back(((YmlList &&) element).complie());
    else if (typeid(element) == typeid(YmlScalar))
        elements.emplace_back(((YmlScalar &&) element));
    else if (typeid(element) == typeid(YmlRoot))//YmlRoot里不能添加YmlRoot
        throw unexpected_type_err
                ("can't adding YmlRoot into YmlRoot:\n"
                 + element.toString());
    else
        throw unknown_type_err
                ("unknown type when adding element into YmlRoot:\n"
                 + element.toString());
}

Self Self::with(const yparser::YmlRaw &ymlRaw) {
    auto raw = ymlRaw.toString();
    if (ymlRaw.isRoot())
        return YmlRoot(raw);
    else
        throw bad_cast();
}
