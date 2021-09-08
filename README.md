# yparser

lite Yaml parser library implemented by cpp14.

WIP.

## 一个轻量级yaml解析库

### 功能列表&计划实现~~Flags~~

- [x] yml完全语法支持
- [x] yml文档格式修正
- [x] 支持注释
- [x] 惰性嵌套解析
- [x] yml对象与字符串的双向序列化
- [ ] 精确索引
- [ ] 基于布隆过滤器的模糊索引
- [ ] 导出yml对象为默克尔树
- [ ] 默克尔校验
- [x] yml转sha256
- [x] 解析异常支持
- [ ] 导出yml对象为json字符串
- [ ] 解析缓存
- [ ] yml对象到本地文件的热重载

### 已知问题&解决

- ~~本parser基于C++标准正则库实现，受限于其NFA效率，在解析较大嵌套结构时（主要是缩进非常多的情况）会卡死。~~ Fixed✅，通过使用boost正则库重写所有匹配逻辑与表达式。
