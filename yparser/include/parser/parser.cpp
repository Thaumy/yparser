//
// Created by Thaumy on 2021/9/8.
//

#include "parser.h"

#define Self parser
#define YmlRaw yparser::YmlRaw


vector<YmlRaw> Self::lazyParser(const string &yml) {
    //(?:^|\n)(\w+:(?: .+|\n)(?:(?:  )+.+\n*)*)(?=\n|$)
    auto results = util::reg::multiSearch//此表达式不应该匹配得到每个节点末的\n
            (yml, R"(^\w+:[\n ](((  )+[^\n]+\n*)+(?=\n|$)|[^\n]+))");//perl syntax

    if (results.empty())//数据集为空直接返回
        return vector<YmlRaw>{};

    vector<YmlRaw> arr;
    arr.reserve(results.size());

    for (const auto &el: results) {
        if (YmlRaw::isMap(el))
            arr.emplace_back(YmlRaw(el, YmlRaw::Type::mapping));
        else if (YmlRaw::isList(el))
            arr.emplace_back(YmlRaw(el, YmlRaw::Type::list));
        else if (YmlRaw::isScalar(el))
            arr.emplace_back(YmlRaw(el, YmlRaw::Type::scalar));
        else//is text
            arr.emplace_back(YmlRaw(el, YmlRaw::Type::text));
    }

    return arr;
}

vector<YmlRaw> Self::lazyParserMT(const string &yml) {
    //(?:^|\n)(\w+:(?: .+|\n)(?:(?:  )+.+\n*)*)(?=\n|$)
    auto results = util::reg::multiSearch//此表达式不应该匹配得到每个节点末的\n
            (yml, R"(^\w+:[\n ](((  )+[^\n]+\n*)+(?=\n|$)|[^\n]+))");//perl syntax

    if (results.empty())//数据集为空直接返回
        return vector<YmlRaw>{};

    vector<YmlRaw> arr;//vector支持并发写入
    arr.resize(results.size());//预初始化全部位置

    typedef std::vector<string>::iterator iter;
    //解析函数
    auto fn = [&arr](iter start, iter afterEnd, int startIndex) {
        while (start < afterEnd) {
            if (YmlRaw::isMap(*start))
                arr[startIndex] = YmlRaw(*start, YmlRaw::Type::mapping);
            else if (YmlRaw::isList(*start))
                arr[startIndex] = YmlRaw(*start, YmlRaw::Type::list);
            else if (YmlRaw::isScalar(*start))
                arr[startIndex] = YmlRaw(*start, YmlRaw::Type::scalar);
            else//is text
                arr[startIndex] = YmlRaw(*start, YmlRaw::Type::text);

            start++;
            startIndex++;//移入下一位置
        }
    };

    const int slice_count = (int) results.size();//总切片数
    const int max_threads = 512;//同时解析的最大线程数
    const int used_threads =//实际使用的线程数
            slice_count > max_threads ? max_threads : slice_count;
    const int avg = slice_count / used_threads;//每线程平均处理切片数，向下取整
    //由于used_threads*avg ≤ slice_count，所以需要将最后一部分切片分配给最后一个线程
    const int last = slice_count - used_threads * avg;//最后一个线程被分配的切片数


    {//处理阶段
        thread ts[used_threads];

        int count = 0;//已处理切片数
        auto begin = results.begin();

        //将avg个切片分配到每一个线程，最后一个线程除外
        for (int i = 0; i < used_threads - 1; ++i) {
            ts[i] = thread(
                    fn,
                    begin + count,
                    begin + count + avg,
                    count
            );

            count += avg;
        }
        //将last个切片分配给最后一个线程
        ts[used_threads - 1] = thread(
                fn,
                begin + count,
                begin + count + last,
                count
        );

        //阻塞到全部线程执行完成
        for (int i = 0; i < used_threads; ++i)
            ts[i].join();
    }

    return arr;
}



/*
vector<YmlRaw> Self::greedyParser(const string &yml) {
    //(?:^|\n)(\w+:(?: .+|\n)(?:(?:  )+.+\n*)*)(?=\n|$)
    auto results = util::reg::multiSearch//此表达式不应该匹配得到每个节点末的\n
            (yml, R"(^\w+:[\n ](((  )+[^\n]+\n*)+(?=\n|$)|[^\n]+))");//perl syntax

    vector<YmlRaw> arr;

    for (const auto &el:results) {
        if (YmlRaw::isMap(el)) {
            auto map_el = YmlMap::with(YmlRaw(el, YmlRaw::Type::mapping));
            arr.emplace_back(map_el);
        } else if (YmlRaw::isList(el)) {
            auto map_list = YmlList::with(YmlRaw(el, YmlRaw::Type::list));
            arr.emplace_back(map_list);
        } else if (YmlRaw::isScalar(el)) {
            auto map_scalar = YmlScalar::with(YmlRaw(el, YmlRaw::Type::scalar));
            arr.emplace_back(map_scalar);
        } else {//is text
            arr.emplace_back(YmlRaw(el, YmlRaw::Type::text));
        }
    }
    return vector<YmlRaw>(arr);
}*/
