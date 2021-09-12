//
// Created by Thaumy on 2021/9/12.
//

#ifndef INCLUDE_ISTREAMABLE_HPP
#define INCLUDE_ISTREAMABLE_HPP

#include "../../globalheaders.h"


namespace interface {
    //可流化接口
    class IStreamable : public ISerializable {
    public:
        //插入到流
        inline friend ostream &operator<<(ostream &o, const IStreamable &src);
    };
}

namespace interface {
    inline ostream &operator<<(ostream &o, const IStreamable &src) {
        return o << src.serialize();
    }
}

#endif //INCLUDE_ISTREAMABLE_HPP
