//
// Created by Thaumy on 2021/9/7.
//

#ifndef INCLUDE_YMLROOT_H
#define INCLUDE_YMLROOT_H

#include "../YmlRaw.h"
#include "../derived/YmlMap.h"
#include "../derived/YmlList.h"
#include "../derived/YmlRoot.h"
#include "../derived/YmlScalar.h"


namespace yparser {
    //无索引结构，抽象为聚合根
    class YmlRoot :
            public YmlRaw,
            public IStreamable {
    public:
        YmlRoot();

        //使用yml构造
        explicit YmlRoot(const string &yml);

        //序列化到字符串
        string serialize() const override;

        //编译表达式
        YmlRoot complie();

    public:
        //将YmlRaw转换为YmlRoot
        static YmlRoot with(const YmlRaw &);

    public:
        vector<YmlRaw> getElements();

        void add(const YmlRaw &element);

    private:
        vector<YmlRaw> elements;
    };
}

#endif //INCLUDE_YMLROOT_H
