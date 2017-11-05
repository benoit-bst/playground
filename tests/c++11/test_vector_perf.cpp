#include <iostream>
#include <vector>
#include <algorithm>

bool myFunction(int i, int j){return (i<j);}

using namespace std;

// Vector
// compile : g++ -std=c++11 test_vector_perf.cpp
int main()
{
  vector<int> v(600000);
  generate(v.begin(), v.end(), std::rand);

  sort(v.begin(), v.end(), myFunction);
  int i = 0;
  for (int i = 0; i < 10000; ++i)
  {
  	i = i + 1;
  }

  sort(v.begin(), v.end(), [](int i, int j) { return (i<j); });

  int ii = 3;
  int j = ++ii;
  std::cout << ii << " - " << j << std::endl;
  // std::cout << ++i << std::endl;
  std::cout << ++ii << std::endl;
}