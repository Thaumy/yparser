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
                for (const auto &k:it->getElements()) {
                    parseAll(k.toString());;
                }
            } else if (el->isScalar()) {
                auto it = YmlScalar::with(el);
                cout << "SCALAR  :" << it->getKey() << endl;
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
    parseAll(yml);;
    //write(raw, path);;

    /*YmlScalar hola("hola", "hello");
    YmlScalar sekai("sekai", "world");
    YmlMap students;
    students.setKey("students");
    {
        YmlMap Joe;
        Joe.setKey("Joe");
        {
            Joe.addElement("phone", YmlScalar("phone", "1951327599"));
            Joe.addElement("message", YmlScalar("message", "thaumy12384"));
            {
                YmlList favorNumbers;
                favorNumbers.setKey("favorNumbers");
                favorNumbers.addElement(YmlRaw("114"));
                favorNumbers.addElement(YmlRaw("514"));
                favorNumbers.addElement(YmlRaw("000"));
                favorNumbers.serialize();
                Joe.addElement("favorNumbers", favorNumbers);
            }
        }
        Joe.serialize();
        YmlMap Alice;
        Alice.setKey("Alice");
        {
            Alice.addElement("message", YmlScalar("message", "good"));
            {
                YmlMap nekos;
                nekos.setKey("nekos");
                nekos.addElement("cat1", YmlScalar("cat1", "jbcat"));
                nekos.addElement("cat2", YmlScalar("cat2", "ooo"));
                nekos.serialize();
                Alice.addElement("nekos", nekos);
            }
        }
        Alice.serialize();

        students.addElement("Alice", Alice);
        students.addElement("Joe", Joe);
    }
    students.serialize();
    YmlMap AwesomeSite;
    AwesomeSite.setKey("AwesomeSite");
    {
        AwesomeSite.addElement("url", YmlScalar("url", "http://cdn.thaumy.cn/"));
    }
    AwesomeSite.serialize();
    YmlList Goods;
    Goods.setKey("Goods");
    {
        YmlList fruits;
        fruits.setKey("fruits");
        {
            YmlRoot root;
            {
                root.addElement(YmlScalar("co", "apple"));
                root.addElement(YmlScalar("keyborad", "qwert"));
            }
            root.serialize();
            fruits.addElement(root);
            fruits.addElement(YmlRaw("banana"));
            fruits.addElement(YmlRaw("cherry"));
        }
        fruits.serialize();;
        Goods.addElement(fruits);
        Goods.addElement(YmlScalar("id1", "1"));
        Goods.addElement(YmlRaw("hybrid"));
    }
    Goods.serialize();
    YmlList List;
    List.setKey("List");
    {
        List.addElement(YmlRaw("12384"));
    }
    List.serialize();

    cout << hola.serialize() << endl
         << sekai.serialize() << endl
         << students.serialize() << endl
         << AwesomeSite.serialize() << endl
         << Goods.serialize() << endl
         << List.serialize() << endl;*/

    return 0;
}
