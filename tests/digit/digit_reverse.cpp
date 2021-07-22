#include <iostream>
#include <string>
#include <set>
#include <algorithm>

#include <stdlib.h>

using namespace std;

// time complexity O()
// space complexity O()
string digit_reverse(long long input) {
  string rev = "";

  input = abs(input);

  while (input > 0) {
    rev += to_string(input % 10);
    input /= 10;
  }
  return rev;
}

// g++ -std=c++11 digit_sum.cpp
int main() {
  int input = 123;
  cout << "digit sum: " << digit_reverse(input) << endl;
  input = 2;
  cout << "digit sum: " << digit_reverse(input) << endl;
  input = 55554;
  cout << "digit sum: " << digit_reverse(input) << endl;
  input = -55554;
  cout << "digit sum: " << digit_reverse(input) << endl;
}
