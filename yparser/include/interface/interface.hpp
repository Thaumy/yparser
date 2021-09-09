//
// Created by Thaumy on 2021/9/4.
//

#ifndef INCLUDE_INTERFACE_HPP
#define INCLUDE_INTERFACE_HPP

#include "../globalheaders.h"


namespace interface {
    //可KV实体接口
    template<typename K, typename V>
    class IKeyValueTangible {//mixin mode
    public:
        //得到键
        virtual K getKey() const { return this->key; }

        //得到值
        virtual V getValue() const { return this->value; }

    protected:
        //设置键
        virtual void setKey(const K &newKey) { this->key = newKey; }

        //设置值
        virtual void setValue(const V &newValue) { this->value = newValue; }

    private:
        K key;
        V value;
    };

    //可哈希接口
    class IHashable {
    public:
        //转SHA256
        virtual string SHA256() const = 0;
    };

    //可字符串接口
    class IStringable {
    public:
        //转字符串
        virtual string toString() const = 0;
    };
}

#endif //INCLUDE_INTERFACE_HPP
