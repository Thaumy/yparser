//
// Created by Thaumy on 2021/9/6.
//

#ifndef INCLUDE_SCALAR_VALUE_PARSE_ERR
#define INCLUDE_SCALAR_VALUE_PARSE_ERR

class scalar_value_parse_err : public yparser_error {
public:
    explicit scalar_value_parse_err(const string &message) : yparser_error(message) {}
};

#endif //INCLUDE_SCALAR_VALUE_PARSE_ERR
