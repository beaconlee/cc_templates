#pragma once
#include <cassert>

template <typename T>
T
max(T a, T b)
{
  return b < a ? a : b;
}

// 关于模板的编译分为两部分:
// 定义时:   若在定义时不进行实例化,则会检查代码的正确性,包括语法错误,使用未知的符号(函数,变量),检查(不依赖于模板参数)静态断言
// 实例化时:  实例化时,会检查和类型相关的正确性
template <typename T>
void
foo(T type)
{
  // 这个两个未声明的都会报错
  // undeclared();
  // undeclared(type);
  // 有个问题时,这两个都出现了错误,但都是在编译后才发现的. 这里说的编译后,是指代码提示没有指出这里有错误
  // static_assert(sizeof(int) > 100, "int is too small");
  // static_assert(sizeof(type) > 10, "T too small");
}