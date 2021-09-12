//
// Created by Thaumy on 2021/9/12.
//

#ifndef INCLUDE_ISERIALIZABLE_HPP
#define INCLUDE_ISERIALIZABLE_HPP

#include "../../globalheaders.h"


namespace interface {
    //可序列化接口
    class ISerializable {
    public:
        //序列化到字符串
        virtual string serialize() const = 0;
    };
}

#endif //INCLUDE_ISERIALIZABLE_HPP
