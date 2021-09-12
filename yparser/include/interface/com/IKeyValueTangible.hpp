//
// Created by Thaumy on 2021/9/12.
//

#ifndef INCLUDE_IKEYVALUETANGIBLE_HPP
#define INCLUDE_IKEYVALUETANGIBLE_HPP

#include "../../globalheaders.h"


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
}

#endif //INCLUDE_IKEYVALUETANGIBLE_HPP
