#include <iostream>
#include <string>
#include <sstream>

#include <yparser.h>
#include <easyio.h>
#include <openssl/sha.h>

using namespace std;
using namespace easyio;
using namespace yparser;

void parseAll(const string &yml) {
    auto parsed = YmlRaw(yml).parse();;
    if (!parsed.empty()) {
        for (auto el:parsed) {
            //cout << "SHA: " << el->SHA256() << endl;
            if (el->isMap()) {
                auto it = YmlMap::with(el);;
                cout << "MAP     :" << it->getKey() << endl;;
                parseAll(it->getValue());
            } else if (el->isList()) {
                auto it = YmlList::with(el);
                cout << "LIST    :" << it->getKey() << endl;;
                for (const auto &k:it->elements) {
                    parseAll(k.toString());;
                }
            } else if (el->isScalar()) {
                auto it = YmlScalar::with(el);
                cout << "SCALAR  :" << it->getKey() << endl;;
                parseAll(it->getValue());
            };
        }
    } else {
        cout << "    TEXT:" << yml << endl;;
    }
}

int main() {
    auto path = R"(../config.yml)";;
    auto yml = *read(path);;
    auto raw = YmlRaw(yml).toString();
    //auto parsed = YmlRaw(yml).parse();
    cout << raw;;;
    /*for (auto el:parsed) {
        cout << "-----------\n";
        YmlMap::with(el);;;;;;;;;;;;;
        //cout <<  << endl;
    }*/
    //parseAll(yml);;
    write(raw, path);;
    return 0;
}
