//
// Created by Thaumy on 2021/9/7.
//

#include "YmlRoot.h"

#define Self yparser::YmlRoot


Self::YmlRoot() : YmlRaw(
        "zero parameter constructor of YmlRoot",//标识到yml方便debug
        text) {}

string Self::serialize() {
    ostringstream serialized;//提高拼接效率

    for (const auto &el:elements) {
        serialized << el.toString() << "\n";//最后会产生空行
    }
    raw = serialized.str();
    util::yml::formatPipeline(raw);
    return raw;
}

void Self::addElement(const yparser::YmlRaw &element) {
    this->elements.emplace_back(element);
}
