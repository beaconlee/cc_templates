#pragma once
#include <cassert>

#include <memory>
#include <typeinfo>
#include <iostream>
#include <cxxabi.h> // GCC/Clang 专用的头文件，用于解码类型名称


template <typename T>
T
max(T a, T b)
{
  return b < a ? a : b;
}


// 辅助函数：解码 typeid 返回的类型名称
// mangled 编码过的
//
inline std::string
demangle(const char *mangled_name)
{
  int status = -1;
  std::unique_ptr<char, void (*)(void *)> res{
      abi::__cxa_demangle(mangled_name, nullptr, nullptr, &status),
      std::free};
  return (status == 0) ? res.get() : mangled_name;
}



// template <typename T>
// T
// max_argu(T a, T b)
// {
//   std::cout << "Type of T: " << demangle(typeid(T).name()) << ", ";
//   return b < a ? a : b;
// }

template <typename T>
T
max_argu(const T a, const T b)
{
  std::cout << "Type of T: " << demangle(typeid(T).name()) << ", ";
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


template <typename T>
void
// f(T /*unused*/ = "")
f(T param = "")
{
  std::cout << "param: " << param << std::endl;
}


template <typename T1, typename T2, typename RT>
RT
max(T1 a, T2 b)
{
  return b < a ? a : b;
}


template <typename RT, typename T1, typename T2>
RT
max_rt(T1 a, T2 b)
{
  return a < b ? a : b;
}