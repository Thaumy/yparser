//
// Created by Thaumy on 2021/9/7.
//

#ifndef INCLUDE_YMLROOT_H
#define INCLUDE_YMLROOT_H

#include "../../globalheaders.h"
#include "../../interface/interface.hpp"
#include "../YmlRaw.h"


namespace yparser {
    //无索引结构，抽象为yml根
    class YmlRoot : public YmlRaw {
    public:
        YmlRoot();

        //序列化到字符串
        string serialize();

    public:
        void addElement(const YmlRaw &element);

    private:
        vector<YmlRaw> elements;
    };
}


#endif //INCLUDE_YMLROOT_H
