//
// Created by Thaumy on 2021/9/4.
//

#ifndef INCLUDE_INTERFACE_H
#define INCLUDE_INTERFACE_H

#include "../globalheaders.h"


namespace interface {
    //可KV实体接口
    class IKeyValueTangible {//mixin mode
    public:
        string getKey() const;

        string getValue() const;

    protected:
        string value;
        string key;
    };

    //可哈希接口
    class IHashable {
    public:
        virtual string SHA256() const = 0;
    };

    //可字符串接口
    class IStringable {
    public:
        virtual string toString() const = 0;
    };
}

#endif //INCLUDE_INTERFACE_H
