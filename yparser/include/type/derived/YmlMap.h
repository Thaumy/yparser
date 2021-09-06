//
// Created by Thaumy on 2021/9/1.
//

#ifndef YPARSER_YMLMAP_H
#define YPARSER_YMLMAP_H

#include "../../globalheaders.h"
#include "../../interface/interface.hpp"
#include "../YmlRaw.h"


namespace yparser {
    class YmlMap : public YmlRaw, public IKeyValueTangible<string, string> {
    public:
        explicit YmlMap(const string &);

    public:
        //将YmlNode转换为YmlMap
        static YmlMap *with(const YmlRaw *);

    public:
        map<string, YmlRaw> elements;
    };
}

#endif //YPARSER_YMLMAP_H
