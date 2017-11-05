#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>

using namespace std;
using std::chrono::nanoseconds;
using std::chrono::duration_cast;

#define NB_VAL 1000000

void vectorReserveThrow(int nb)
{
	vector<double> tmp;
	tmp.reserve(nb);
}

void vectorReserveNoThrow(int nb) noexcept
{
	vector<double> tmp;
	tmp.reserve(nb);
}

void vectorReserveNoThrow2(int nb) throw()
{
	vector<double> tmp;
	tmp.reserve(nb);
}

/*
 * compile : g++ -std=c++11 test_noexcept.cpp
 *
 */
int main()
{
	auto t1 = std::chrono::high_resolution_clock::now();
	vectorReserveThrow(NB_VAL);
  auto t2 = std::chrono::high_resolution_clock::now();
  auto diff = t2 - t1;
  nanoseconds ns = duration_cast<nanoseconds>(diff);
  std::cout << "reserve with throw  - " << ns.count() << " nano" << std::endl;

  t1 = std::chrono::high_resolution_clock::now();
  vectorReserveNoThrow2(NB_VAL);
  t2 = std::chrono::high_resolution_clock::now();
  diff = t2 - t1;
  ns = duration_cast<nanoseconds>(diff);
  std::cout << "reserve with no throw  - " << ns.count() << " nano" << std::endl;

  t1 = std::chrono::high_resolution_clock::now();
  vectorReserveNoThrow(NB_VAL);
  t2 = std::chrono::high_resolution_clock::now();
  diff = t2 - t1;
  ns = duration_cast<nanoseconds>(diff);
  std::cout << "reserve with no throw  - " << ns.count() << " nano" << std::endl;

  t1 = std::chrono::high_resolution_clock::now();
	vectorReserveThrow(NB_VAL);
  t2 = std::chrono::high_resolution_clock::now();
  diff = t2 - t1;
  ns = duration_cast<nanoseconds>(diff);
  std::cout << "reserve with throw  - " << ns.count() << " nano" << std::endl;

  t1 = std::chrono::high_resolution_clock::now();
  vectorReserveNoThrow2(NB_VAL);
  t2 = std::chrono::high_resolution_clock::now();
  diff = t2 - t1;
  ns = duration_cast<nanoseconds>(diff);
  std::cout << "reserve with no throw  - " << ns.count() << " nano" << std::endl;

  t1 = std::chrono::high_resolution_clock::now();
  vectorReserveNoThrow(NB_VAL);
  t2 = std::chrono::high_resolution_clock::now();
  diff = t2 - t1;
  ns = duration_cast<nanoseconds>(diff);
  std::cout << "reserve with no throw  - " << ns.count() << " nano" << std::endl;

  /*
		reserve with no throw  - 6969 nano
		reserve with no throw  - 343 nano
		reserve with throw  - 186 nano     !!
		reserve with no throw  - 208 nano  !! ==
		reserve with no throw  - 182 nano  !!

		Same thing

  */
}