//
// Created by Thaumy on 2021/9/6.
//

#ifndef SCALAR_KEY_PARSE_ERR
#define SCALAR_KEY_PARSE_ERR

class scalar_key_parse_err : public yparser_error {
public:
    explicit scalar_key_parse_err(const string &message) : yparser_error(message) {}
};

#endif //SCALAR_KEY_PARSE_ERR
