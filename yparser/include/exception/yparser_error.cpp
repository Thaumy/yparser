//
// Created by Thaumy on 2021/9/6.
//

#include "yparser_error.h"

#define Self yparser_error

Self::yparser_error(const string &message) {
    this->message = message;
}

const char *Self::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT {
    return this->message.c_str();
}

