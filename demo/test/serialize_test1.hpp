//
// Created by Thaumy on 2021/9/8.
//

#include <iostream>
#include <string>
#include <yparser.h>
#include "io_yml_string.hpp"


using namespace std;
using namespace easyio;
using namespace yparser;

void serialize_test() {
    YmlRoot ymlroot;
    {
        YmlScalar hola("hola", "hello");
        YmlScalar sekai("sekai", "world");
        YmlMap students("students");
        {
            YmlMap Joe("Joe");
            {
                Joe.add(YmlScalar("phone", "1951327599"));
                Joe.add(YmlScalar("message", "thaumy12384"));
                {
                    YmlList favorNumbers("favorNumbers");
                    favorNumbers.add(YmlRaw("114"));
                    favorNumbers.add(YmlRaw("514"));
                    favorNumbers.add(YmlRaw("000"));
                    Joe.add(favorNumbers);
                }
            }
            YmlMap Alice("Alice");
            {
                Alice.add(YmlScalar("message", "good"));
                {
                    YmlMap nekos("nekos");
                    nekos.add(YmlScalar("cat1", "jbcat"));
                    nekos.add(YmlScalar("cat2", "ooo"));
                    Alice.add(nekos);
                }
            }

            students.add(Alice);
            students.add(Joe);
        }
        YmlMap AwesomeSite("AwesomeSite");
        {
            AwesomeSite.add(YmlScalar("url", "http://cdn.thaumy.cn/"));
        }
        YmlList Goods("Goods");
        {
            YmlList fruits("fruits");
            {
                YmlRoot root;
                {
                    root.add(YmlScalar("co", "apple"));
                    root.add(YmlScalar("keyborad", "qwert"));
                }
                fruits.add(root);
                YmlList noKeyList("");
                {
                    YmlList noKeyList1("");
                    {
                        YmlList noKeyList2("");
                        {
                            noKeyList2.add(YmlRaw("a"));
                            noKeyList2.add(YmlRaw("b"));
                        }
                        noKeyList1.add(noKeyList2);
                    }
                    noKeyList.add(noKeyList1);
                }
                fruits.add(noKeyList);
                fruits.add(YmlRaw("banana"));
                fruits.add(YmlRaw("cherry"));
            }
            Goods.add(fruits);
            Goods.add(YmlScalar("id1", "1"));
            Goods.add(YmlRaw("hybrid"));
        }
        YmlList List("List");
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