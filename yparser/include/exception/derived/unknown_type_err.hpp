//
// Created by Thaumy on 2021/9/6.
//

#ifndef UNKNOWN_TYPE_ERR
#define UNKNOWN_TYPE_ERR

class unknown_type_err : public yparser_error {
public:
    explicit unknown_type_err(const string &message) : yparser_error(message) {}
};

#endif //UNKNOWN_TYPE_ERR
