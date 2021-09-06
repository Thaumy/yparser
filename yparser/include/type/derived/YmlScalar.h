//
// Created by Thaumy on 2021/9/1.
//

#ifndef YPARSER_YMLSCALAR_H
#define YPARSER_YMLSCALAR_H

#include "../../globalheaders.h"
#include "../../interface/interface.hpp"
#include "../YmlRaw.h"


namespace yparser {
    class YmlScalar : public YmlRaw, public IKeyValueTangible<string, string> {
    public:
        explicit YmlScalar(const string &);

    public:
        //将YmlNode转换为YmlScalar
        static YmlScalar *with(const YmlRaw *);

    public:
        //TODO
    };
}

#endif //YPARSER_YMLSCALAR_H
