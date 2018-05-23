#include <limits>
#include <iostream>
#include <cmath>

#include <stddef.h>
#include <stdalign.h>

// Type and declaration
// compile : g++ -std=c++11 test_limits.cpp
int main()
{
  std::cout << "Troncate char :" << std::endl << std::endl;

  unsigned char c1 = 64;
  unsigned char c2 = 1256;
  std::cout << "unsigned char c1 = 64 - c1 = " << (int)c1 << std::endl;
  std::cout << "unsigned char c2 = 1256 - c2 = " << (int)c2 << " car 2^8=256"<< std::endl;

  std::cout << "Test les fonctions limits :" << std::endl << std::endl;

  void*ptrv;
  int *ptri;
  std::cout << "size of void pointer  : " << sizeof(ptrv) << std::endl;
  std::cout << "size of int  pointer  : " << sizeof(ptri) << std::endl;

  std::cout << "size of char          : " << sizeof(char) << std::endl;
  std::cout << "size of bool          : " << sizeof(bool) << std::endl;

  std::cout << "size of int           : " << sizeof(int) << std::endl;
  std::cout << "size of size_t        : " << sizeof(size_t) << std::endl;
  std::cout << "size of int8_t        : " << sizeof(int8_t) << std::endl;
  std::cout << "size of int16_t       : " << sizeof(int16_t) << std::endl;
  std::cout << "size of int32_t       : " << sizeof(int32_t) << std::endl;
  std::cout << "size of int64_t       : " << sizeof(int64_t) << std::endl;
  std::cout << "size of uint8_t       : " << sizeof(uint8_t) << std::endl;
  std::cout << "size of uint32_t      : " << sizeof(uint32_t) << std::endl;


  std::cout << "size of short         : " << sizeof(short) << " - max : " << std::numeric_limits< short >::max() << " - min : " << std::numeric_limits< short >::min() << " - 2^" << sizeof(short)*8 << "=" << std::pow(2,sizeof(short)*8) << std::endl;
  std::cout << "size of int           : " << sizeof(int) << " - max : " << std::numeric_limits< int >::max() << " - min : " << std::numeric_limits< int >::min() << " - 2^" << sizeof(int)*8 << "=" << std::pow(2,sizeof(int)*8) << std::endl;
  std::cout << "size of float         : " << sizeof(float) << " - max : " << std::numeric_limits< float >::max() << " - min : " << std::numeric_limits< float >::min() << std::endl;
  std::cout << "size of long          : " << sizeof(long) << " - max : " << std::numeric_limits< long >::max() << " - min : " << std::numeric_limits< long >::min() << std::endl;
  std::cout << "size of long long     : " << sizeof(long long) << " - max : " << std::numeric_limits< long long >::max() << " - min : " << std::numeric_limits< long long >::min() << std::endl;
  std::cout << "size of long long int : " << sizeof(long long int) << " - max : " << std::numeric_limits< long long int >::max() << " - min : " << std::numeric_limits< long long int >::min() << std::endl;
  std::cout << "size of 1L            : " << sizeof(1L) << std::endl;
  std::cout << "size of double        : " << sizeof(double) << " - max : " << std::numeric_limits< double >::max() << " - min : " << std::numeric_limits< double >::min() << std::endl;
  std::cout << "size of long double   : " << sizeof(long double) << " - max : " << std::numeric_limits< long double >::max() << " - min : " << std::numeric_limits< long double >::min() << std::endl << std::endl;

  std::cout << "std::numeric_limits< int >::radix  : " << std::numeric_limits< int >::radix << std::endl;
  std::cout << "std::numeric_limits< int >::digits : " << std::numeric_limits< int >::digits << std::endl;

//   std::cout << "size of char          :" << std::alignof(1) << std::endl;

}
