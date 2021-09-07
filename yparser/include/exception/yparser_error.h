//
// Created by Thaumy on 2021/9/6.
//

#ifndef INCLUDE_YPARSER_ERROR_H
#define INCLUDE_YPARSER_ERROR_H

#include <exception>
#include <string>


using namespace std;

class yparser_error : public exception {
public:
    explicit yparser_error(const string &message);

    const char *what() const noexcept override {
        return this->message.c_str();
    }

private:
    string message;
};

#endif //INCLUDE_YPARSER_ERROR_H
