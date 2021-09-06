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
        K getKey() const {
            return K(key);
        }

        //得到值
        V getValue() const {
            return V(value);
        }

    protected:
        //设置键
        void setKey(K newKey) {
            this->key = std::move(newKey);
        }

        //设置值
        void setValue(V newValue) {
            this->value = std::move(newValue);
        }

    private:
        K key;
        V value;
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

#endif //INCLUDE_INTERFACE_HPP
