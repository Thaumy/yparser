//
// Created by Thaumy on 2021/9/1.
//

#ifndef YPARSER_YMLMAP_H
#define YPARSER_YMLMAP_H

#include "../../globalheaders.h"
#include "../../interface/interface.hpp"
#include "../YmlRaw.h"


namespace yparser {
    //yml映射
    class YmlMap : public YmlRaw, public IKeyValueTangible<string, string> {
    public:
        YmlMap();//由于C++不支持程序集访问级别，故此处不使用键构造

        //使用yml构造
        explicit YmlMap(const string &yml);

        //序列化到字符串
        string serialize();

        //编译表达式
        void complie();

    public:
        //将YmlRaw转换为YmlMap
        static YmlMap with(const YmlRaw &);

    public:
        //设置键
        void setKey(const string &key) override;

        //添加元素
        void addElement(const string &key, const YmlRaw &value);

        //取得元素
        YmlRaw getElementValue(const string &key);

        //取元素值列表
        vector<YmlRaw> getElementValues();

    private:
        map<string, YmlRaw> elements;
    };
}

#endif //YPARSER_YMLMAP_H
