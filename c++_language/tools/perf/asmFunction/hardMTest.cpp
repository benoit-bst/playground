#include <iostream>
#include <vector>
#include "hardM.h"

/*
 * compile : g++ -std=c++11 hardMTest.cpp
 *
 */
int main()
{
  hardM::cpuid();
  uint64_t start = hardM::rdtsc();
  std::vector<int> v;
  v.push_back(1000);
  uint64_t now = hardM::rdtscp();
  hardM::cpuid();
  int64_t ts = now - start;

  std::cout << "rdtsc  : " << start << "\n";
  std::cout << "rdtscp : " << now << "\n";
  std::cout << "ts     : " << ts << "\n";
  // std::cout << "cpuid  : " << cpuid << "\n";
}