#include <iostream>
#include <vector>
#include <algorithm>

#include <stdio.h>

using namespace std;

#define VECTOR(nbRand)                     \
  vector<int> v(nbRand);                   \
  generate(v.begin(), v.end(), std::rand); \

// Vector
// compile : g++ test.cpp
int main()
{
  printf("__LINE__ %d\n", __LINE__);
  printf("__FILE__ %s\n", __FILE__);

  VECTOR(10)
  cout << "V Size : " << v.size() << endl;
}