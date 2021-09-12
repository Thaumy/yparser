//
// Created by Thaumy on 2021/9/12.
//

#ifndef INCLUDE_ISTRINGABLE_HPP
#define INCLUDE_ISTRINGABLE_HPP

#include "../../globalheaders.h"


namespace interface {
    //可字符串接口
    class IStringable {
    public:
        //转字符串
        virtual string toString() const = 0;
    };
}

#endif //INCLUDE_ISTRINGABLE_HPP
