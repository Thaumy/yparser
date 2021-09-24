#include "easyio.h"

//read file into string
string easyio::read(const string &src) {
    ifstream file;
    file.open(src, ios::in);

    ostringstream stream;

    stream << file.rdbuf();//get all string from file
    file.close();

    return stream.str();
}

//clear file and write string to file
void easyio::write(const string &str, const string &tar) {
    ofstream file;
    file.open(tar, ios::out);

    file << str;//put string to file
    file.close();
}