#include <iostream>
#include <cfloat>

/*
 * compile : g++ -std=c++11 test_impliciteConversion.cpp
 *
 * char, signed char, unsigned char, short int -> int (sinon signed int)
 * bool -> int (false devient 0)
 */
int main()
{  
  // Pointeur -> bool
  std::cout << std::boolalpha; // permet l'affichage de 0 a false
  int *p = 0;
  bool nulle = p;
  std::cout << "bool *p=0 : " << nulle << std::endl;

  // float -> int
  int i = 2.7;
  std::cout << "int 2.7 : " << i << std::endl;

  // float -> double
  float f = FLT_MAX;
  std::cout << "float  FLT_MAX : " << f << std::endl;
  double d = f;
  std::cout << "double FLT_MAX : " << d << std::endl;
  d = DBL_MAX;
  std::cout << "double DBL_MAX : " << d << std::endl;
  f = d;
  std::cout << "float  DBL_MAX : " << f << std::endl;
}