//
// Created by Thaumy on 2021/9/1.
//

#ifndef YPARSER_YMLNODE_H
#define YPARSER_YMLNODE_H

#include "../globalheaders.h"
#include "../interface/interface.h"
#include "../util/util.h"


using namespace interface;

namespace yparser {
    class YmlRaw : public IHashable, public IStringable {
    public:
        string SHA256() const override;

        string toString() const override;

        enum Type {//使用mapping与std::map区分
            mapping, list, scalar, text
        };

    public:
        //使用字符串构造
        explicit YmlRaw(string yml);

        virtual ~YmlRaw() = default;

    private:
        //使用字符串构造，同时指明类型（此构造对用户透明）
        explicit YmlRaw(string yml, Type type);

    public:
        //自解析
        vector<YmlRaw *> parse(const bool &lazy = true) const;

        //是映射
        bool isMap() const;

        //是列表
        bool isList() const;

        //是纯量
        bool isScalar() const;

        //是文本（即非Map、List或Scalar）
        bool isText() const;

    private:
        string raw;//yml原生字符串
        Type type;//当前类型，对用户透明

        //是映射
        static bool isMap(const string &yml);

        //是列表
        static bool isList(const string &yml);

        //是纯量
        static bool isScalar(const string &yml);
    };

}
#endif //YPARSER_YMLNODE_H
