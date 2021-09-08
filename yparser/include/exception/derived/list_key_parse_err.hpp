//
// Created by Thaumy on 2021/9/6.
//

#ifndef INCLUDE_LIST_KEY_PARSE_ERR
#define INCLUDE_LIST_KEY_PARSE_ERR

class list_key_parse_err : public yparser_error {
public:
    explicit list_key_parse_err(const string &message) : yparser_error(message) {}
};

#endif //INCLUDE_LIST_KEY_PARSE_ERR
