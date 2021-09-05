//
// Created by Thaumy on 2021/9/1.
//

#ifndef YPARSER_YMLLIST_H
#define YPARSER_YMLLIST_H

#include "../../globalheaders.h"
#include "../../interface/interface.h"
#include "../YmlRaw.h"


namespace yparser {
    class YmlList : public YmlRaw, public IKeyValueTangible {
    public:
        explicit YmlList(const string &);

    public:
        //将YmlNode转换为YmlList
        static YmlList *with(const YmlRaw *);

    public:
        vector<YmlRaw> elements;
    };
}

#endif //YPARSER_YMLLIST_H
