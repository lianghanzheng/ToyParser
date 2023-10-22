# ToyParser

本项目基于Dmitry Soshnikov的课程Essentials of Parsing。

处于教学目的，parser将源代码转换为json形式的AST，从实现上的便利考虑使用了javascript作为实现语言。

本人因为很久没有用C++编写过程序了，所以将其javascript实现转换为了C++实现。其中对于json的处理原本打算自己编写一个简单的库练手，结果发现写了很久还没有进入第一讲的内容，于是方便起见使用了boost库中JSON处理模块。

依赖：
1. gcc/clang编译器
2. boost库 (本人使用的是1.83.0)

## 添加program节点

在lesson1-1中，我们直接将数字字面量节点作为了整个程序。虽然是通过 `program` 进行的解析，但是并未添加起始符号 `Program`。

现在，我们需要将字符串中的序列解析为token，因此引入了 `Tokenizer`。偷懒起见，对Token的识别可以直接用regex库进行。

本阶段实现目标：
1. 编写 `Tokenizer` 来识别数字字面量、字符串
2. `Tokenizer` 能够识别异常状态并输出错误信息
3. `Tokenizer` 能够跳过空白字符
4. `Tokenizer` 能够跳过注释
