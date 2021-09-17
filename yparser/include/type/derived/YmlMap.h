//
// Created by Thaumy on 2021/9/1.
//

#ifndef YPARSER_YMLMAP_H
#define YPARSER_YMLMAP_H

#include "../YmlRaw.h"
#include "../derived/YmlMap.h"
#include "../derived/YmlList.h"
#include "../derived/YmlRoot.h"
#include "../derived/YmlScalar.h"


namespace yparser {
    //yml映射
    class YmlMap :
            public YmlRaw,
            public IStreamable,
            public IKeyValueTangible<string, string> {
    public:
        YmlMap();//由于C++不支持程序集访问级别，故此处不使用键构造

        //使用yml构造
        explicit YmlMap(const string &yml);

        //序列化到字符串
        string serialize() const override;

        //编译表达式
        YmlMap complie();

    public:
        //将YmlRaw转换为YmlMap
        static YmlMap with(const YmlRaw &);

    public:
        //设置键
        [[deprecated("Please use constructor to set key")]]
        void setKey(const string &key) override;

        //添加元素，键从元素推断
        void add(const YmlRaw &value);

        //添加元素并显式指定键，已弃用
        [[deprecated("Please use 'void add(const YmlRaw &value)'")]]
        void add(const string &key, const YmlRaw &value);

        //取得元素，已弃用
        [[deprecated("Please use 'YmlRaw operator[](const string &key)'")]]
        YmlRaw getElementValue(const string &key);

        //使用键值访问
        YmlRaw operator[](const string &key);

        //取元素值列表
        vector<YmlRaw> getElementValues();

    private:
        map<string, YmlRaw> elements;

        //使用yml构造，禁止初始化
        //YmlMap(const string &yml, bool &noInit = true);
    };
}

#endif //YPARSER_YMLMAP_H
