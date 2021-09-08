//
// Created by Thaumy on 2021/9/7.
//

#ifndef INCLUDE_YMLROOT_H
#define INCLUDE_YMLROOT_H

#include "../../globalheaders.h"
#include "../../interface/interface.hpp"
#include "../YmlRaw.h"


namespace yparser {
    //无索引结构，抽象为聚合根
    class YmlRoot : public YmlRaw {
    public:
        YmlRoot();

        //使用yml构造
        explicit YmlRoot(const string &yml);

        //序列化到字符串
        string serialize();

        //编译表达式
        void complie();

    public:
        //将YmlRaw转换为YmlRoot
        static YmlRoot with(const YmlRaw &);

    public:
        vector<YmlRaw> getElements();

        void addElement(const YmlRaw &element);

    private:
        vector<YmlRaw> elements;
    };
}


#endif //INCLUDE_YMLROOT_H
