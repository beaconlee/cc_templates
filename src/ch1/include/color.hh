#include <string>
#include <vector>
#include <iostream>


// 定义颜色枚举
enum class Color
{
  Black = 30,
  Red = 31,
  Green = 32,
  Yellow = 33,
  Blue = 34,
  Magenta = 35,
  Cyan = 36,
  White = 37
};

// 定义样式枚举
enum class Style
{
  Reset = 0,
  Bold = 1,
  Underline = 4
};

// 生成ANSI转义序列
inline std::string
make_ansi_sequence(const std::vector<int> &codes)
{
  std::string seq = "\033[";
  for(size_t i = 0; i < codes.size(); ++i)
  {
    seq += std::to_string(codes[i]);
    if(i < codes.size() - 1)
    {
      seq += ";";
    }
  }
  seq += "m";
  return seq;
}

// 彩色输出函数
inline void
print_colored(const std::string &text,
              Color fg = Color::White,
              Color bg = Color::Black,
              Style style = Style::Reset)
{
  std::vector<int> codes;
  if(style != Style::Reset)
  {
    codes.push_back(static_cast<int>(style));
  }
  codes.push_back(static_cast<int>(fg)); // 前景色
  // codes.push_back(static_cast<int>(bg) + 10); // 背景色（前景色代码 + 10）

  std::string seq = make_ansi_sequence(codes); // 生成转义序列
  std::string reset = make_ansi_sequence({0}); // 重置序列

  std::cout << seq << text << reset << std::endl; // 输出带颜色的文本并重置
}

// 定义内联函数替代宏
inline void
red(const std::string &text)
{
  print_colored(text, Color::Red, Color::Black, Style::Reset);
}

inline void
green(const std::string &text)
{
  print_colored(text, Color::Green, Color::Black, Style::Reset);
}

inline void
blue(const std::string &text)
{
  print_colored(text, Color::Blue, Color::Black, Style::Reset);
}

inline void
yellow(const std::string &text)
{
  print_colored(text, Color::Yellow, Color::Black, Style::Reset);
}

inline void
magenta(const std::string &text)
{
  print_colored(text, Color::Magenta, Color::Black, Style::Reset);
}