//
// Created by Thaumy on 2021/9/6.
//

#ifndef INCLUDE_MAP_VALUE_PARSE_ERR
#define INCLUDE_MAP_VALUE_PARSE_ERR

class map_value_parse_err : public yparser_error {
public:
    explicit map_value_parse_err(const string &message) : yparser_error(message) {}
};

#endif //INCLUDE_MAP_VALUE_PARSE_ERR
