#include "max.hh"

#include <iostream>

void
demo()
{
  std::cout << "this is max\n";
  int i = 47;
  std::cout << "max(2, 47):" << ::max(2, i) << "\n";
  float const a = 2.3;
  float b = 3.3;
  std::cout << "max(2.3, 3.3):" << ::max(a, b) << "\n";
  std::string s1 = "beacon";
  std::string s2 = "uan";
  std::cout << R"(max("beacon", "uan":))" << ::max(s1, s2) << "\n";
}


void
two_phase_translation()
{
  foo(2);
}


void
argument_deduction()
{
  int i = 42;
  int uan = 43;
  int const j = 23;
  int &a = i;
  int const &b = i;
  int arr[4] = {2, 3, 4, 5};
  std::cout << "max_argu(2.2, 2.2):" << ::max_argu(&i, &uan) << "\n";
}

// int64_t  a =
int
main()
{
  // demo();
  demo();

  // two_phase_translation();
  two_phase_translation();

  // argument_deduction

  argument_deduction();
  return 0;
}
