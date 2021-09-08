//
// Created by Thaumy on 2021/9/3.
//

#include "util.h"

#define Self util


using namespace boost;

string Self::reg::singleSearch(const string &str, const string &expr, const int &position) {
    smatch sm;
    regex_search(str, sm, regex(expr));

    return sm[position].str();
}

vector<string> Self::reg::multiSearch(const string &str, const string &expr, const int &position) {
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

bool Self::yml::isSingleLine(string &yml) {
    //cout << "isSingleLine" << endl;
    regex expr(R"(\n)");
    auto mode = regex_constants::format_first_only;//只搜索第一个匹配项
    return !regex_search(yml, expr, mode);
}

void Self::yml::fixIndentation(string &yml) {
    //cout << "fixIndentation" << endl;
    auto mode = regex_constants::format_first_only;//只搜索第一个匹配项
    {//对奇数缩进增加一个空格
        //\n (?:  )*(?=[^ ]+)
        regex expr(R"(\n (?:  )*(?=[^ ]+))");
        smatch sm;
        while (regex_search(yml, sm, expr)) {
            yml = regex_replace(yml, expr, sm.str() + " ", mode);
        }
    }
    {//修复单元素的错误缩进
        //\n[^ \n]+\n(?:   +| )(?=[-\w][^\n]+\n?)
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

void Self::yml::delAnnotation(string &yml) {
    //cout << "delAnnotation" << endl;
    // #.+
    regex expr(R"((^| )#[^\n]+)");//perl syntax
    yml = regex_replace(yml, expr, "");
}

void Self::yml::decIndentation(string &yml) {
    //cout << "decIndentation" << endl;
    //  (?=\w|-)
    regex expr(R"(^  )");//perl syntax
    yml = regex_replace(yml, expr, "");
}

void Self::yml::incIndentation(string &yml) {
    //cout << "incIndentation" << endl;
    regex expr(R"(^(?=[^\n]+))");//perl syntax
    yml = regex_replace(yml, expr, "  ");
}

void Self::yml::delBlankLine(string &yml) {
    //cout << "delBlankLine" << endl;
    {//去除最后一行之前的所有空行
        //\n( *\n*)*(?:\n)
        regex expr(R"(^ *\n)");//perl syntax
        yml = regex_replace(yml, expr, "\n");
    }
    {//如果最后一行是空行，去除最后一行
        regex expr(R"(\n *$)");
        yml = regex_replace(yml, expr, "");
    }
}

void Self::yml::delLineEndSpace(string &yml) {
    //cout << "delLineEndSpace" << endl;
    // +(?=\n)| +$
    regex expr(R"( *$)");//perl syntax
    yml = regex_replace(yml, expr, "");
}

void Self::yml::formatPipeline(string &yml) {
    //格式化函数流水线
    function<void(string &)> pipeline[] =
            {delAnnotation,//删除注释
             delBlankLine,//清除空行
             delLineEndSpace,//清除行尾空格
             fixIndentation};//修复错误缩进
    for (const auto &f:pipeline)
        f(yml);//按照流水线处理yml
}
