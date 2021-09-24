//
// Created by Thaumy on 2021/9/5.
//

#ifndef INCLUDE_GLOBALHEADERS_H
#define INCLUDE_GLOBALHEADERS_H

#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <vector>
#include <thread>
#include <cmath>
#include <map>

//#include <regex>
#include <boost/regex.hpp>
#include <openssl/sha.h>
#include <easyio.h>

#include "exception/yparser_error.h"
#include "exception/derived/map_key_parse_err.hpp"
#include "exception/derived/map_value_parse_err.hpp"
#include "exception/derived/list_key_parse_err.hpp"
#include "exception/derived/list_value_parse_err.hpp"
#include "exception/derived/scalar_key_parse_err.hpp"
#include "exception/derived/scalar_value_parse_err.hpp"
#include "exception/derived/unknown_type_err.hpp"
#include "exception/derived/unexpected_type_err.hpp"

#endif //INCLUDE_GLOBALHEADERS_H
