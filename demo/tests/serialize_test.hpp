//
// Created by Thaumy on 2021/9/8.
//

#include <iostream>
#include <string>
#include <yparser.h>


using namespace std;
using namespace easyio;
using namespace yparser;

void serialize_test(){
    YmlScalar hola("hola", "hello");
    YmlScalar sekai("sekai", "world");;
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
                favorNumbers.complie();
                Joe.addElement("favorNumbers", favorNumbers);
            }
        }
        Joe.complie();
        YmlMap Alice;
        Alice.setKey("Alice");
        {
            Alice.addElement("message", YmlScalar("message", "good"));
            {
                YmlMap nekos;
                nekos.setKey("nekos");
                nekos.addElement("cat1", YmlScalar("cat1", "jbcat"));
                nekos.addElement("cat2", YmlScalar("cat2", "ooo"));
                nekos.complie();
                Alice.addElement("nekos", nekos);
            }
        }
        Alice.complie();

        students.addElement("Alice", Alice);
        students.addElement("Joe", Joe);
    }
    students.complie();
    YmlMap AwesomeSite;
    AwesomeSite.setKey("AwesomeSite");
    {
        AwesomeSite.addElement("url", YmlScalar("url", "http://cdn.thaumy.cn/"));
    }
    AwesomeSite.complie();
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
            root.complie();
            fruits.addElement(root);
            fruits.addElement(YmlRaw("banana"));
            fruits.addElement(YmlRaw("cherry"));
        }
        fruits.complie();;
        Goods.addElement(fruits);
        Goods.addElement(YmlScalar("id1", "1"));
        Goods.addElement(YmlRaw("hybrid"));
    }
    Goods.complie();
    YmlList List;
    List.setKey("List");
    {
        List.addElement(YmlRaw("12384"));
    }
    List.complie();

    cout << hola.serialize() << endl
         << sekai.serialize() << endl
         << students.serialize() << endl
         << AwesomeSite.serialize() << endl
         << Goods.serialize() << endl
         << List.serialize() << endl;
}