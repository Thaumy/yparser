//
// Created by Thaumy on 2021/9/4.
//

#include "interface.h"

#define Self interface::IKeyValueTangible


string Self::getKey() const {
    return string(key);
}

string Self::getValue() const {
    return string(value);
}
