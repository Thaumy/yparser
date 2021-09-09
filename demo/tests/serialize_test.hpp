//
// Created by Thaumy on 2021/9/8.
//

#include <iostream>
#include <string>
#include <yparser.h>


using namespace std;
using namespace easyio;
using namespace yparser;

void serialize_test() {
    YmlRoot ymlroot;
    {
        YmlScalar hola("hola", "hello");
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
                    Joe.addElement("favorNumbers", favorNumbers);
                }
            }
            YmlMap Alice;
            Alice.setKey("Alice");
            {
                Alice.addElement("message", YmlScalar("message", "good"));
                {
                    YmlMap nekos;
                    nekos.setKey("nekos");
                    nekos.addElement("cat1", YmlScalar("cat1", "jbcat"));
                    nekos.addElement("cat2", YmlScalar("cat2", "ooo"));
                    Alice.addElement("nekos", nekos);
                }
            }

            students.addElement("Alice", Alice);
            students.addElement("Joe", Joe);
        }
        YmlMap AwesomeSite;
        AwesomeSite.setKey("AwesomeSite");
        {
            AwesomeSite.addElement("url", YmlScalar("url", "http://cdn.thaumy.cn/"));
        }
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
                fruits.addElement(root);
                fruits.addElement(YmlRaw("banana"));
                fruits.addElement(YmlRaw("cherry"));
            }
            Goods.addElement(fruits);
            Goods.addElement(YmlScalar("id1", "1"));
            Goods.addElement(YmlRaw("hybrid"));
        }
        YmlList List;
        List.setKey("List");
        {
            List.addElement(YmlRaw("12384"));
        }

        ymlroot.addElement(hola);
        ymlroot.addElement(sekai);
        ymlroot.addElement(students);
        ymlroot.addElement(AwesomeSite);
        ymlroot.addElement(Goods);
        ymlroot.addElement(List);
    }

    cout << ymlroot.serialize();
}