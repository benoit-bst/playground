#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;
using std::chrono::nanoseconds;
using std::chrono::duration_cast;

static const char* stringVal = "156";

int fast_atoi(const char* str)
{
	int val = 0;
	while (*str)
	{
		val = val*10 + (*str++ - '0');
	}
	return val;
}

/*
 * compile : g++ -std=c++11 test_stringToInt.cpp
 *
 */
int main()
{
	auto t1 = std::chrono::high_resolution_clock::now();
	int a = fast_atoi(stringVal);
  auto t2 = std::chrono::high_resolution_clock::now();
  auto diff = t2 - t1;
  nanoseconds ns = duration_cast<nanoseconds>(diff);
  std::cout << "fast_atoi  - " << ns.count() << " nano - " << a << std::endl;

  t1 = std::chrono::high_resolution_clock::now();
  int b = atoi(stringVal);
  t2 = std::chrono::high_resolution_clock::now();
  diff = t2 - t1;
  ns = duration_cast<nanoseconds>(diff);
  std::cout << "atoi  - " << ns.count() << " nano - " << b << std::endl;

  t1 = std::chrono::high_resolution_clock::now();
  int c = stoi(stringVal);
  t2 = std::chrono::high_resolution_clock::now();
  diff = t2 - t1;
  ns = duration_cast<nanoseconds>(diff);
  std::cout << "stoi  - " << ns.count() << " nano - " << c << std::endl;

  /*
    fast_atoi  - 124 nano - 156
    atoi  - 1284 nano - 156
    atoi  - 31065 nano - 156
  */
}