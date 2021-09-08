//
// Created by Thaumy on 2021/9/6.
//

#ifndef INCLUDE_ROOT_PARSE_ERR
#define INCLUDE_ROOT_PARSE_ERR

class root_parse_err : public yparser_error {
public:
    explicit root_parse_err(const string &message) : yparser_error(message) {}
};

#endif //INCLUDE_ROOT_PARSE_ERR
