//
// Created by Thaumy on 2021/9/6.
//

#ifndef INCLUDE_SCALAR_KEY_PARSE_ERR
#define INCLUDE_SCALAR_KEY_PARSE_ERR

class scalar_key_parse_err : public yparser_error {
public:
    explicit scalar_key_parse_err(const string &message) : yparser_error(message) {}
};

#endif //INCLUDE_SCALAR_KEY_PARSE_ERR
