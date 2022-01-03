#include <iostream>

using namespace std;

int foo(){
  return foo();
}

double fact(double n) {
    if (n <= 0) return 1;
    else return n * fact(n - 1);
}

/*
 * compile : g++ -stackoverflow.cpp
 */
int main()
{
  // {
  //   double array[1048576];
  //   array[1000] = 20.0;
  // }

  {
    foo();
  }

  // {
    // std::cout << "fact(5) = " << fact(5) << std::endl;
    // std::cout << "fact(10) = " << fact(10) << std::endl;
  //   std::cout << "fact(100) = " << fact(100) << std::endl;
  //   std::cout << "fact(1000) = " << fact(1000) << std::endl;
  // }



}