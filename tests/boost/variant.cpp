#include <boost/variant.hpp>
#include <iostream>
#include <string>

/**
 * Generic container (one data with different type).
 * Comparable à l'union
 *
 * compile : g++ variant.cpp
 */
int main(int argc, char const *argv[])
{
  typedef boost::variant<int, std::string, bool> myVar;

  myVar x = std::string("hello");
  myVar y = 20;
  myVar z = false;

  std::string s = boost::get<std::string>(x);
  int i = boost::get<int>(y);
  bool b = boost::get<bool>(z);

  switch (x.which()){
  case 0:
    std::cout << "int" << std::endl;
    break;
  case 1:
    std::cout << "std::string" << std::endl;
    break;
  case 2:
    std::cout << "bool" << std::endl;
    break;
  }

  x = 20;

  switch (x.which()){
  case 0:
    std::cout << "int" << std::endl;
    break;
  case 1:
    std::cout << "std::string" << std::endl;
    break;
  case 2:
    std::cout << "bool" << std::endl;
    break;
  }

  return 0;
}