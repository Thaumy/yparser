//
// Created by Thaumy on 2021/9/8.
//

#include <iostream>
#include <string>
#include <yparser.h>
#include <easyio.h>
#include "io_yml_string.hpp"


using namespace std;
using namespace easyio;
using namespace yparser;

void greedyParseAll(const vector<YmlRaw> &parsed) {
    for (const auto &el: parsed) {
        //cout << "SHA: " << el.SHA256() << endl;
        if (el.isMap()) {
            auto it = YmlMap::with(el);
            cout << "MAP     :" << it.getKey() << endl;
            greedyParseAll(it.getElementValues());

        } else if (el.isList()) {
            auto it = YmlList::with(el);
            cout << "LIST    :" << it.getKey() << endl;
            greedyParseAll(it.getElements());

        } else if (el.isScalar()) {
            auto it = YmlScalar::with(el);
            cout << "SCALAR  :" << it.getKey() << endl;
            cout << "    TEXT:" << it.getValue() << endl;

        } else if (el.isRoot()) {
            auto it = YmlRoot::with(el);
            cout << "ROOT    :" << endl;
            greedyParseAll(it.getElements());

        } else
            cout << "    TEXT:" << el.toString() << endl;
    }
}

void parse_test() {
    auto yml = get_yml_string();
    auto obj = YmlRaw(yml, parser::lazyParserMT);
    auto parsed = obj.parse();

    greedyParseAll(parsed);
}
