#include <iostream>
#include <string>
#include <set>
#include <algorithm>

#include <stdlib.h>

using namespace std;

// time complexity O()
// space complexity O()
int digit_sum(long long input) {
  int sum = 0;

  input = abs(input);

  while (input > 0) {
    sum += input % 10;
    input /= 10;
  }
  return sum;
}

// g++ -std=c++11 digit_sum.cpp
int main() {
  int input = 123;
  cout << "digit sum: " << digit_sum(input) << endl;
  input = 2;
  cout << "digit sum: " << digit_sum(input) << endl;
  input = 55554;
  cout << "digit sum: " << digit_sum(input) << endl;
  input = -55554;
  cout << "digit sum: " << digit_sum(input) << endl;
}
