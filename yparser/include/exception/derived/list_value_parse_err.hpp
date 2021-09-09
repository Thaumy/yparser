//
// Created by Thaumy on 2021/9/6.
//

#ifndef LIST_VALUE_PARSE_ERR
#define LIST_VALUE_PARSE_ERR

class list_value_parse_err : public yparser_error {
public:
    explicit list_value_parse_err(const string &message) : yparser_error(message) {}
};

#endif //LIST_VALUE_PARSE_ERR
