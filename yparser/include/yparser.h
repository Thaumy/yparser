#ifndef YPARSER_YPARSER_H
#define YPARSER_YPARSER_H

//...
#include "interface/interface.h"
#include "parser/parser.h"
#include "util/util.h"

//errs
#include "exception/yparser_error.h"
#include "exception/derived/list_key_parse_err.hpp"
#include "exception/derived/list_value_parse_err.hpp"
#include "exception/derived/map_key_parse_err.hpp"
#include "exception/derived/map_value_parse_err.hpp"
#include "exception/derived/scalar_key_parse_err.hpp"
#include "exception/derived/scalar_value_parse_err.hpp"

//types
#include "type/YmlRaw.h"
#include "type/derived/YmlMap.h"
#include "type/derived/YmlList.h"
#include "type/derived/YmlScalar.h"
#include "type/derived/YmlRoot.h"

#endif //YPARSER_YPARSER_H
