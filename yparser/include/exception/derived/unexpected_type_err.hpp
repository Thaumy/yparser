//
// Created by Thaumy on 2021/9/6.
//

#ifndef UNEXPECTED_TYPE_ERR
#define UNEXPECTED_TYPE_ERR

class unexpected_type_err : public yparser_error {
public:
    explicit unexpected_type_err(const string &message) : yparser_error(message) {}
};

#endif //UNEXPECTED_TYPE_ERR
