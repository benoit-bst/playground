#include <iostream>
#include <vector>
#include <algorithm>

bool myFunction(int i, int j){return (i<j);}

using namespace std;

// Gcov
// g++ -std=c++11 -fprofile-arcs -ftest-coverage test_gcov.cpp
// ./a.out
// gcov test_gcov.cpp
// cat test_gcov.cpp.gcov

// Lcov
// lcov --base-directory . --directory . --capture --output-file test_gcov.info
// genhtml -o ./test_gcov test_gcov.info
int main()
{
  vector<int> v(1000);

  for (int i = 0; i < 1000; ++i)
  {
    v.push_back(i);
  }

}