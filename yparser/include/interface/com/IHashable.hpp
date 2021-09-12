//
// Created by Thaumy on 2021/9/12.
//

#ifndef INCLUDE_IHASHABLE_HPP
#define INCLUDE_IHASHABLE_HPP

#include "../../globalheaders.h"


namespace interface {
//可哈希接口
    class IHashable {
    public:
        //转SHA256
        virtual string SHA256() const = 0;
    };

}

#endif //INCLUDE_IHASHABLE_HPP
