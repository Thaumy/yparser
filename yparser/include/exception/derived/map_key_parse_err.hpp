//
// Created by Thaumy on 2021/9/6.
//

#ifndef INCLUDE_MAP_KEY_PARSE_ERR_HPP
#define INCLUDE_MAP_KEY_PARSE_ERR_HPP

class map_key_parse_err : public yparser_error {
public:
    explicit map_key_parse_err(const string &message) : yparser_error(message) {}
};

#endif //INCLUDE_MAP_KEY_PARSE_ERR_HPP
