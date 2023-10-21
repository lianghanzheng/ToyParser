# ToyParser

本项目基于Dmitry Soshnikov的课程Essentials of Parsing。

处于教学目的，parser将源代码转换为json形式的AST，从实现上的便利考虑使用了javascript作为实现语言。

本人因为很久没有用C++编写过程序了，所以将其javascript实现转换为了C++实现。其中对于json的处理原本打算自己编写一个简单的库练手，结果发现写了很久还没有进入第一讲的内容，于是方便起见使用了boost库中JSON处理模块。

依赖：
1. gcc/clang编译器
2. boost库 (本人使用的是1.83.0)