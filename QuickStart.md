# yparser

轻量级Yaml解析器

## yparser概要

yparser是一种轻量级的Yaml解释器，基于C++14开发。

yparser是被作为项目构建的基础设施而设计的。通过使用yparser，我们能够将`.yml`文件解析到yparser内建的数据对象，从而极大地简化对数据的识别操作。同样地，使用yparser内建的数据对象，我们也能够轻松地以类似DSL语言的形式将数据序列化到Yaml字符串并在本地以文本的形式储存起来。

## yparser能够做什么

本着轻量级的原则，yparser提供了有关于Yaml构建的全部基础设施。

* [x] yml基本语法支持
* [x] yml文档格式修正
* [x] 注释识别
* [x] 惰性嵌套解析
* [x] 并发解析
* [x] yml对象与字符串的双向序列化
* [x] yml到SHA256签名
* [x] 解析异常支持
* [x] 自定义解析过程

## yparser是如何工作的

yparser是基于正则表达式的。通过使用正则语言，yparser能够轻松识别Yaml的语法类型、嵌套关系、注释文本甚至是Yaml中的错误。首先，yparser会通过一系列内置的语法模板将原始的Yaml字符串进行划分，并对Yaml字符流进行规范化。然后，通过使用更加详细的识别模板，yparser能够分析出原Yaml文档中每一个划分的具体类型，从而针对这些特定类型的语法模式进行快速而有效的解析识别。所有的解析结果都会反映到yparser中内置的Yaml对象上，允许你通过面向对象的方式来访问你所需要的数据。

yparser的序列化流程同样精简高效，它通过识别你在特定内置Yaml对象中添加的数据来生成原始的Yaml语法树，并自下而上地将语法树的每一部分编译到Yaml表达式。当整个Yaml语法树编译完成时，你就得到了一串正确的、符合Yaml规范的Yaml文本。

## Yaml概要

Yaml是一种人类可读的数据序列化语言。  

通过使用Yaml，可以方便地表达各种数据形态，例如列表、散列表、标量等等。Yaml与Json是同构的，Json能够表示的数据Yaml也能够有效表示，且两者可以转换，但Yaml提供了比Json高许多的可读性，这使得它十分适合作为各种与人类交互的、小型的数据文本，例如配置文件。Yaml的全称是YAML Ain‘t Markup Language（Yaml不是标记语言），是Yet Another Markup Language的递归缩写。

Yaml的文件以`.yml`后缀结尾。

## Yaml基本语法概要

为增强可读性，Yaml使用双空格进行缩进以表示层级嵌套关系。  

Yaml支持三种数据形式，它们分别是**映射**（Mapping）、**列表**（List）和**纯量**（Scalar）。

* 映射

```Yaml
goods:
  a1: phone 
  b2: computer
  c3: book
```

映射用于表示可以抽象为键-值对的数据形态。

* 列表

```Yaml
fruits:
  - apple
  - banana
  - cherry
```

列表用于表示某一类数据的集合。

嵌套列表也是被允许的：

```Yaml
example:
  - 
    - a
    - b
    - c
  - 
    bar:
      - a
      - b
  - cherry
```

* 纯量

```Yaml
student1: Anna
student2: Ben
student3: Thaumy
```

纯量是最简单的数据形式，它描述了一个名字和它蕴含的值。

通过混合使用以上三种类型，我们能够构造任意复杂的数据形态。  
例如，某班级中学生的概要信息：

```Yaml
Class1: 
  934770716910:
    first_name: Thaumy
    last_name: Cheng
    sex: male
    phone: 1234567890
    hobby: 
      - coding
      - read book
      - fishing
  385271188675:
    first_name: Alice
    last_name: Miyabi
    sex: female
    phone: 1527561890
    hobby: 
      - small talk
      - sleeping
  105507332749:
    first_name: Tim
    last_name: Cook
    sex: male
    phone: 1136569821
    hobby: 
      - #This hobby can be broken down
        sell_things:
          - iphone
          - mac
          - etc
      - clear inventory
```

Yaml同样支持`#注释`，这可以让文档更加清晰。

## 快速入门的最佳实践

### 解析Yaml

yparser集成了一个简单的IO库（easyio），可使用`read`函数简单地读入目标文件`tar.yml`到字符串。

```C++
auto path = R"(tar.yml)";
auto yml = *read(path);
```

按照如下方式构造`YmlRaw`对象即可解析Yaml字符串到一个`vector<YmlRaw>`，其中包含了Yaml字符串的所有解析结果。

```C++
auto parsed = YmlRaw(yml, parser::lazyParser).parse();
```

`parser::lazyParser`是yparser的标准惰性解析器，它支持以惰性求值的方式完成对目标文本的解析。

yparser支持自定义解析器，你可以通过编写符合`function<vector<YmlRaw>(const string &)>`函数式接口标准的自定义函数来接管解析控制流。可选用不同的解析器以满足不同场景下的解析需要。

例如，parser::lazyParserMT是parser::lazyParser的并发版本，为切换到该解析器，只需更改到以下代码：

```C++
auto parsed = YmlRaw(yml, parser::lazyParserMT).parse();
```

> ≥1.1.0版本的parser::lazyParserMT完全可用。

### 序列化到Yaml

yparser支持以类DSL的方式构造目标Yaml文本。

例如：

```C++
YmlScalar hola("hello", "yparser");
```

通过调用`serialize`函数，将Yml对象序列化到字符串：

```C++
cout << hola.serialize();//hello: yparser
```

`≥1.0.6`版本的yparser重载了流插入运算符，可以直接将对象插入到流而无需调用显式序列化过程。

```C++
cout << YmlScalar("hola", "hello");//hello: yparser
```

该重载适用但不限于`YmlScalar`的所有`YmlRaw`派生类。

这是上述"学生的概要信息"案例的一部分的简化版与构造示例：

```Yaml
105507332749:
  name: Tim
  phone: 1136569821
  hobby: 
    -
      sell_things:
        - iphone
        - mac
    - clear inventory
```

```C++
YmlMap map("105507332749");
{
  map.add(YmlScalar("first_name", "Tim"));
  map.add(YmlScalar("phone", "1136569821"));
  YmlList list("hobby");
  {
    YmlList el("sell_things");
    {
      el.add(YmlRaw("iphone"));
      el.add(YmlRaw("mac"));
    }
    list.add(el);
    list.add(YmlRaw("clear inventory"));
  }
  map.add(list);
}
```

`≥1.0.7`版本的yparser支持在为`YmlMap`添加元素时自动推断键，否则需要显式指定键值：

```C++
map.add("phone", YmlScalar("phone", "1136569821"));
```

`≤1.0.6`版本的yparser不支持智能构造器（构造函数值推断字符串是键还是yml字符串），需要显式调用`setKey`函数：

```C++
map.setKey("105507332749");
```

### 示例

项目目录中的`demo`工程对上述两种操作类型进行了详尽演示。

## 版本迭代历史

* 1.1.0（Sep26，21）
  * Fixed bugs of concurrent parser.
* 1.0.9（Sep25，21）
  * Added concurrent parser.
* 1.0.8（Sep18，21）
  * Improved exception feedback.
  * Supported keyless list.
  * Supported over indentation correction for same level elements of the list.
* 1.0.7（Sep16，21）
  * Added smart constructor.
  * More convenient to add elements into YmlMap.
* 1.0.6 (Sep12, 21)
  * More convenient construction syntax.
* 1.0.5 (Sep9, 21)
  * Improved exception system further.
  * Auto YmlMap/List/Scalar/Root complie.
  * Improved type identification further by RTTI.
* 1.0.4 (Sep9, 21)
  * Improved exception system.
  * Improved type identification and type conversion system.
  * Simplified lazy parsing process.
  * Customizable parser.
  * Fixed some parsing bugs.
* 1.0.3 (Sep8, 21)
  * Supported the serialization of YmlRaw to string.
  * Introduced formatting pipeline.
* 1.0.2 (Sep6, 21)
  * Fixed parsing bugs.
  * Replaced std regex to boost regex to improve efficiency and and * optimize codes.
* 1.0.1 (Sep6, 21)
  * Added exception system
  * Changed IKeyValueTangible into template
  * Normalized codes
* 1.0.0 (Sep5, 21)
  * Basic parsing functions.

## 项目参见

GitHub [https://github.com/Thaumy/yparser/](https://github.com/Thaumy/yparser/)
