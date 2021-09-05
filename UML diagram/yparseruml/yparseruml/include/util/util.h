//
// Created by Thaumy on 2021/9/3.
//

#ifndef YPARSER_UTIL_H
#define YPARSER_UTIL_H

#include "../globalheaders.h"


using namespace std;

namespace util {
    //正则表达式单值搜索
    string regexSingleSearch(const string &str, const string &expr, const int &position = 0);

    //正则表达式多值搜索
    vector<string> regexMultiSearch(const string &str, const string &expr, const int &position = 0);


    //修复yml缩进
    void fixIndentation(string &);

    //删除yml注释
    void delAnnotation(string &);

    //减少yml缩进(2space)
    void decIndentation(string &);

    //删除yml空行
    void delBlankLine(string &);

    //删除yml行末空格
    void delLineEndSpace(string &);

    string stringToSHA256(const string &str);
}
#endif //YPARSER_UTIL_H