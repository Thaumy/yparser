//
// Created by Thaumy on 2021/9/1.
//

#ifndef YPARSER_YMLLIST_H
#define YPARSER_YMLLIST_H

#include "../YmlRaw.h"
#include "../derived/YmlMap.h"
#include "../derived/YmlList.h"
#include "../derived/YmlRoot.h"
#include "../derived/YmlScalar.h"


namespace yparser {
    //yml列表
    class YmlList :
            public YmlRaw,
            public IStreamable,
            public IKeyValueTangible<string, string> {
    public:
        YmlList();//由于C++不支持程序集访问级别，故此处不使用键构造

        //使用yml构造
        explicit YmlList(const string &ymlOrKey);

        //序列化到字符串
        string serialize() const override;

        //编译表达式
        YmlList complie();

    public:
        //设置键
        [[deprecated("Please use constructor to set key")]]
        void setKey(const string &newKey) override;

        //添加元素
        void add(const YmlRaw &element);

        //取元素表
        vector<YmlRaw> getElements();

    public:
        //将YmlRaw转换为YmlList
        static YmlList with(const YmlRaw &);

    private:
        vector<YmlRaw> elements;

        //使用yml构造，禁止初始化
        //YmlList(const string &yml, bool &noInit = true);
    };
}

#endif //YPARSER_YMLLIST_H
