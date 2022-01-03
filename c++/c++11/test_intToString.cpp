#include <iostream>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <string>

extern "C"{
  #include <stdlib.h>
}

using namespace std;
using std::chrono::nanoseconds;
using std::chrono::duration_cast;

/*
 * compile : g++ -std=c++11 test_intToString.cpp
 *
 */
int main()
{
  int a = 10;
  char buffer [33];

  auto t1 = std::chrono::high_resolution_clock::now();
  string s = to_string(a); 
  auto t2 = std::chrono::high_resolution_clock::now();
  auto diff = t2 - t1;
  nanoseconds ns = duration_cast<nanoseconds>(diff);
  std::cout << "std::to_string - " << ns.count() << " nano - " << s.c_str() << std::endl;  

  t1 = std::chrono::high_resolution_clock::now();
  sprintf(buffer, "%d", a);
  t2 = std::chrono::high_resolution_clock::now();
  diff = t2 - t1;
  ns = duration_cast<nanoseconds>(diff);
  std::cout << "sprintf - " << ns.count() << " nano - " << buffer << std::endl;

  ostringstream oss;
  t1 = std::chrono::high_resolution_clock::now();
  oss << 10;
  string s2 = oss.str();
  t2 = std::chrono::high_resolution_clock::now();
  diff = t2 - t1;
  ns = duration_cast<nanoseconds>(diff);
  std::cout << "ostringstream  - " << ns.count() << " nano - " << s2.c_str() << std::endl;

  /*
    std::to_string - 35373 nano - 10
    sprintf - 882 nano - 10
    ostringstream  - 3826 nano - 10
  */
}