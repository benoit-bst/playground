#include <boost/any.hpp>
#include <iostream>

/**
 * Generic container for single values of different value types
 *
 * compile : g++ any.cpp
 */
int main(int argc, char const *argv[])
{
  boost::any a = 1;
  std::cout << "int : " << boost::any_cast<int>(a) << std::endl;
  a = 3.14;
  std::cout << "double : " << boost::any_cast<double>(a) << std::endl;
  a = true;
  std::cout << "bool : " << boost::any_cast<bool>(a) << std::endl;
  return 0;
}
