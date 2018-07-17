#include <iostream>
#include <string>

// String
// compile : g++ -std=c++11 test_string.cpp
int main()
{
  std::cout << "Raw string :" << std::endl << std::endl;
  
  std::string s = R"(\w\\w)";
  std::cout << "string s :" << s << std::endl;

  std::string s1 {R"(1
22
333)"};

  std::cout << "string s1 :" << s1 << std::endl;
  
  std::string s2 {"1\n22\n333"};
  
  std::cout << "string s2 :" << s2 << std::endl;

  std::string s22 = R"#(stop_area . uri ( "OIF:42" ) )#";
  std::cout << "string s22 :" << s22 << std::endl;
}
