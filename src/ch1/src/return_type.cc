#include "max.hh"
#include "color.hh"

int
main()
{
  auto m = max<int, int, double>(1, 2);
  // c++ 编译器在生成类型信息时会对类型名称进行编码(mangling),以支持函数重载或其它语言特性.
  // abi::__cxa_demangle 是 gcc 和 clang 提供的一个函数,用于将这种编码过的名称解码(demangling)
  // abi: application binary interface 是应用程序与操作系统或其它应用程序之间二进制接口规范.
  // cxa: common c++ abi
  std::cout << "m:" << m << "\n";
  std::cout << "m mangling:" << typeid(m).name() << "\n";
  int status = -1;
  std::unique_ptr<char, void (*)(void *)> res{
      abi::__cxa_demangle(typeid(m).name(), nullptr, nullptr, &status),
      std::free};


  const auto *result = (status == 0) ? res.get() : typeid(m).name();

  std::cout << "demangle result:" << result << "\n";


  std::cout << "------------\n";

  // green_cout << "hello " << "\n";

  return 0;
}
