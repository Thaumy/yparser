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
                Joe.add("phone", YmlScalar("phone", "1951327599"));
                Joe.add("message", YmlScalar("message", "thaumy12384"));
                {
                    YmlList favorNumbers;
                    favorNumbers.setKey("favorNumbers");
                    favorNumbers.add(YmlRaw("114"));
                    favorNumbers.add(YmlRaw("514"));
                    favorNumbers.add(YmlRaw("000"));
                    Joe.add("favorNumbers", favorNumbers);
                }
            }
            YmlMap Alice;
            Alice.setKey("Alice");
            {
                Alice.add("message", YmlScalar("message", "good"));
                {
                    YmlMap nekos;
                    nekos.setKey("nekos");
                    nekos.add("cat1", YmlScalar("cat1", "jbcat"));
                    nekos.add("cat2", YmlScalar("cat2", "ooo"));
                    Alice.add("nekos", nekos);
                }
            }

            students.add("Alice", Alice);
            students.add("Joe", Joe);
        }
        YmlMap AwesomeSite;
        AwesomeSite.setKey("AwesomeSite");
        {
            AwesomeSite.add("url", YmlScalar("url", "http://cdn.thaumy.cn/"));
        }
        YmlList Goods;
        Goods.setKey("Goods");
        {
            YmlList fruits;
            fruits.setKey("fruits");
            {
                YmlRoot root;
                {
                    root.add(YmlScalar("co", "apple"));
                    root.add(YmlScalar("keyborad", "qwert"));
                }
                fruits.add(root);
                fruits.add(YmlRaw("banana"));
                fruits.add(YmlRaw("cherry"));
            }
            Goods.add(fruits);
            Goods.add(YmlScalar("id1", "1"));
            Goods.add(YmlRaw("hybrid"));
        }
        YmlList List;
        List.setKey("List");
        {
            List.add(YmlRaw("12384"));
        }

        ymlroot.add(hola);
        ymlroot.add(sekai);
        ymlroot.add(students);
        ymlroot.add(AwesomeSite);
        ymlroot.add(Goods);
        ymlroot.add(List);
    }

    cout << ymlroot;
}