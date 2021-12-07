//
// Created by Thaumy on 2021/9/1.
//

#ifndef YPARSER_YMLRAW_H
#define YPARSER_YMLRAW_H

#include "../globalheaders.h"
#include "../interface/interface.h"
#include "../util/util.h"


using namespace interface;

namespace yparser {
    class YmlRaw :
            public IHashable,
            public IStringable {

    public:
        string SHA256() const override;

        string toString() const override;

        enum Type {//使用mapping与std::map区分
            mapping, list, scalar, root, text
        };

    public:
        //仅用于容器默认初始化，非安全的构造器
        YmlRaw();

        //使用字符串构造（可选解析器）
        explicit YmlRaw(string yml,
                        const function<vector<YmlRaw>(const string &)> &parser = nullptr);

        //使用字符串构造，同时指明类型（可选解析器）
        explicit YmlRaw(string yml, Type type,
                        const function<vector<YmlRaw>(const string &)> &parser = nullptr);

    public:
        vector<YmlRaw> parse() const;

        //是映射
        bool isMap() const;

        //是列表
        bool isList() const;

        //是纯量
        bool isScalar() const;

        //是聚合根
        bool isRoot() const;

        //是文本（即非Map、List、Scalar或Root）
        bool isText() const;

        //是映射
        static bool isMap(const string &yml);

        //是列表
        static bool isList(const string &yml);

        //是纯量
        static bool isScalar(const string &yml);

        //是聚合根
        static bool isRoot(const string &yml);

    protected:
        string raw;//yml原生字符串
        static Type getType(const string &yml);//得到yml类型

    private:
        Type type;//当前类型，对用户透明
        function<vector<YmlRaw>(const string &)> parser;//解析器
    };


}


#endif //YPARSER_YMLRAW_H
