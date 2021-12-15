#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
Common Child, is a HackerRank problem from String Manipulation subdomain. In this post we will see how we can solve this challenge in C++

Problem Description
A string is said to be a child of a another string if it can be formed by deleting 0 or more characters from the other string. Given two strings of equal length, what's the longest string that can be ....

-------------------------

test
e

dp 1 1 : 0
dp 2 1 : 1
dp 3 1 : 1
dp 4 1 : 1

test
es

dp 1 1 : 0
dp 1 2 : 0
dp 2 1 : 1
dp 2 2 : 1
dp 3 1 : 1
dp 3 2 : 2
dp 4 1 : 1
dp 4 2 : 2

*/
int main() {
  string s1, s2;
  cin >> s1 >> s2;

  vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));

  for (int i = 1; i < s1.size() + 1; i++) {
    for (int j = 1; j < s2.size() + 1; j++) {

      if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
          dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
      cout << "dp " << i << " " << j << " : " << dp[i][j] << endl;
    }
  }

  cout << dp[s1.size()][s2.size()];

  return 0;
}
