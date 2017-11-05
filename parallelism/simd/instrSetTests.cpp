#include <iostream>
#include "instrSet/InstrSet.hpp"

/**
 * g++ -O3 -msse3 -mavx -mavx2 -mfma instrSet/InstrSet.cpp instrSetTests.cpp
 */
int main(int argc, char const *argv[])
{
  {
    std::cout << "Detect      : " << Dspp::instrset_detect() << std::endl;
    std::cout << "FMA suport  : " << Dspp::hasFMA3() << std::endl;
    std::cout << "FMA suport  : " << Dspp::hasAVX512ER() << std::endl;
    std::cout << "Gcc version : " << GCC_VERSION << std::endl;
  }

  return 0;
}