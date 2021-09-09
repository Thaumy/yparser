//
// Created by Thaumy on 2021/9/6.
//

#ifndef SCALAR_VALUE_PARSE_ERR
#define SCALAR_VALUE_PARSE_ERR

class scalar_value_parse_err : public yparser_error {
public:
    explicit scalar_value_parse_err(const string &message) : yparser_error(message) {}
};

#endif //SCALAR_VALUE_PARSE_ERR
