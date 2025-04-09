#include "max.hh"

#include <iostream>


int
main()
{
  std::cout << "this is max\n";
  int i = 47;
  std::cout << "max(2, 47):" << ::max(2, i) << "\n";
  float a = 2.3;
  float b = 3.3;
  std::cout << "max(2.3, 3.3):" << ::max(a, b) << "\n";
  std::string s1 = "beacon";
  std::string s2 = "uan";
  std::cout << R"(max("beacon", "uan":))" << ::max(s1, s2) << "\n";

  foo(2);
  
  return 0;
}