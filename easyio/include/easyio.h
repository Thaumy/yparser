#ifndef EASYIO_EASYIO_H
#define EASYIO_EASYIO_H

#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

namespace easyio {
    //从src读字符串
    string read(const string &src);

    //写str到tar
    void write(const string &str, const string &tar);
}

#endif //EASYIO_EASYIO_H
