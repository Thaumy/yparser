//
// Created by Thaumy on 2021/9/6.
//

#ifndef MAP_KEY_PARSE_ERR
#define MAP_KEY_PARSE_ERR

class map_key_parse_err : public yparser_error {
public:
    explicit map_key_parse_err(const string &message) : yparser_error(message) {}
};

#endif //MAP_KEY_PARSE_ERR
