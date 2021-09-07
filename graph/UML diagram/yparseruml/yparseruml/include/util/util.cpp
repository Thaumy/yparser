//
// Created by Thaumy on 2021/9/3.
//

#include "util.h"

#define Self util


string Self::regexSingleSearch(const string &str, const string &expr, const int &position) {
    smatch sm;
    regex_search(str, sm, regex(expr));

    return sm[position].str();
}

vector<string> Self::regexMultiSearch(const string &str, const string &expr, const int &position) {
    vector<string> results;

    string::const_iterator pos = str.begin();
    string::const_iterator end = str.end();

    smatch sm;
    while (regex_search(pos, end, sm, regex(expr))) {
        results.emplace_back(sm[position].str());
        pos = sm[0].second;
    }

    return vector<string>(results);
}

string Self::stringToSHA256(const string &str) {
    char buf[2];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);

    ostringstream stream;//使用流提升效率
    for (unsigned char i : hash) {
        sprintf(buf, "%02x", i);
        stream << buf;
    }
    return stream.str();
}

void Self::fixIndentation(string &yml) {
    //cout << "fixIndentation" << endl;
    auto mode = regex_constants::format_first_only;//只搜索第一个匹配项
    {//对奇数缩进增加一个空格
        regex expr(R"(\n (?:  )*(?=[^ ]+))");
        smatch sm;
        while (regex_search(yml, sm, expr)) {
            yml = regex_replace(yml, expr, sm.str() + " ", mode);
        }
    }
    {//修复单元素的错误缩进
        //原表达式为：\n[^ ]+:\n(?:   +| )(?=(?:[^ :]+: |- )[^\n]+(?:\n[^ ]+|$))
        //由于C++regex基于NFA，所以匹配单元素缩进超多的情况时效率很差。
        regex expr(R"(\n[^ \n]+\n(?:   +| )(?=[-\w][^\n]+\n?))");
        smatch sm;
        while (regex_search(yml, sm, expr, mode)) {
            //提取出不正确的缩进头，更改其缩进为2
            auto formatted = regex_replace(sm.str(), regex(R"(:\n +$)"), ":\n  ");
            //将不正确的缩进头替换为正确的缩进头
            yml = regex_replace(yml, expr, formatted, mode);
        }
    }
}

void Self::delAnnotation(string &yml) {
    //cout << "delAnnotation" << endl;
    regex expr(R"( #.+)");
    yml = regex_replace(yml, expr, "");
}

void Self::decIndentation(string &yml) {
    regex expr(R"(  (?=\w|-))");
    yml = regex_replace(yml, expr, "");
}

void Self::delBlankLine(string &yml) {
    //cout << "delBlankLine" << endl;
    {//去除最后一行之前的所有空行
        regex expr(R"(\n( *\n*)*(?:\n))");
        yml = regex_replace(yml, expr, "\n");
    }
    {//如果最后一行是空行，去除最后一行
        regex expr(R"(\n *$)");
        yml = regex_replace(yml, expr, "");
    }
}

void Self::delLineEndSpace(string &yml) {
    //cout << "delLineEndSpace" << endl;
    regex expr(R"( +(?=\n)| +$)");
    yml = regex_replace(yml, expr, "");
}