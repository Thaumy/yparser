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
    YmlMap map;
    map.setKey("105507332749");
    {
        map.add(YmlScalar("first_name", "Tim"));
        map.add(YmlScalar("phone", "1136569821"));
        YmlList list;
        list.setKey("hobby");
        {
            YmlList el;
            el.setKey("sell_things");
            {
                el.add(YmlRaw("iphone"));
                el.add(YmlRaw("mac"));
            }
            list.add(el);
            list.add(YmlRaw("clear inventory"));
        }
        map.add(list);
    }
    
    cout << map;
}