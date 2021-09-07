//
// Created by Thaumy on 2021/9/1.
//

#ifndef YPARSER_YMLLIST_H
#define YPARSER_YMLLIST_H

#include "../../globalheaders.h"
#include "../../interface/interface.hpp"
#include "../../exception/yparser_error.h"
#include "../YmlRaw.h"


namespace yparser {
    //yml列表
    class YmlList : public YmlRaw, public IKeyValueTangible<string, string> {
    public:
        YmlList();//由于C++不支持程序集访问级别，故此处不使用键构造

        //使用yml构造
        explicit YmlList(const string &yml);

        //序列化到字符串
        string serialize();
    public:
        //设置键
        void setKey(const string &newKey) override;

        //添加元素
        void addElement(const YmlRaw &element);

        //取元素表
        vector<YmlRaw> getElements();

    public:
        //将YmlNode转换为YmlList
        static YmlList *with(const YmlRaw *);//TODO 建议接口化

    private:
        vector<YmlRaw> elements;
    };
}

#endif //YPARSER_YMLLIST_H
