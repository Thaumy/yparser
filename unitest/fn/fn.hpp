//
// Created by Thaumy on 2021/9/18.
//

#ifndef UNITEST_FN_HPP
#define UNITEST_FN_HPP

void recParse(ostringstream &os, const vector<YmlRaw> &parsed) {
    for (const auto &el: parsed) {
        //cout << "SHA: " << el.SHA256() << endl;
        if (el.isMap()) {
            auto it = YmlMap::with(el);
            os << "MAP     :" << it.getKey() << endl;;
            recParse(os, it.getElementValues());
        } else if (el.isList()) {
            auto it = YmlList::with(el);
            os << "LIST    :" << it.getKey() << endl;;
            recParse(os, it.getElements());
        } else if (el.isScalar()) {
            auto it = YmlScalar::with(el);
            os << "SCALAR  :" << it.getKey() << endl;
            os << "    TEXT:" << it.getValue() << endl;;
        } else if (el.isRoot()) {
            auto it = YmlRoot::with(el);
            os << "ROOT    :" << endl;
            recParse(os, it.getElements());
        } else {
            os << "    TEXT:" << el.toString() << endl;
        }
    }
}

#endif //UNITEST_FN_HPP
