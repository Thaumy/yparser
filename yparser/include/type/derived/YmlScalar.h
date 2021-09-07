//
// Created by Thaumy on 2021/9/1.
//

#ifndef YPARSER_YMLSCALAR_H
#define YPARSER_YMLSCALAR_H

#include "../../globalheaders.h"
#include "../../interface/interface.hpp"
#include "../YmlRaw.h"


namespace yparser {
    //yml纯量
    class YmlScalar : public YmlRaw, public IKeyValueTangible<string, string> {
    public:
        //使用键值对构造
        YmlScalar(const string &key, const string &value);

        //使用yml构造
        explicit YmlScalar(const string &yml);

        //序列化到字符串
        string serialize();

    public:
        //TODO

    public:
        //将YmlNode转换为YmlScalar
        static YmlScalar *with(const YmlRaw *);
    };
}

#endif //YPARSER_YMLSCALAR_H
