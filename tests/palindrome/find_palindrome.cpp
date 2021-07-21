#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int find_palindromes_in_sub_string(const string& input, int j, int k) {
  int count = 0;
  for (; j >= 0 && k < input.length(); --j, ++k) {
    if (input[j] != input[k]) {
      break;
    }
    cout << input.substr(j, k - j + 1) << endl;
    ++count;
  }
  return count;
}

// time complexity O(N^2)
// space complexity O(1)
int find_all_palindrome(const string& input) {
  int count = 0;
  for (int i = 0; i < input.length(); ++i) {
    count += find_palindromes_in_sub_string(input, i - 1, i + 1);
    count += find_palindromes_in_sub_string(input, i, i + 1);
  }
  return count;
}

int main() {
  string str = "aa";
  cout << "Total palindrome substrings: "  << find_all_palindrome(str) << endl;
  str = "aab";
  cout << "Total palindrome substrings: "  << find_all_palindrome(str) << endl;
  str = "aabbbaa";
  cout << "Total palindrome substrings: "  << find_all_palindrome(str) << endl;
  str = "aabaa";
  cout << "Total palindrome substrings: "  << find_all_palindrome(str) << endl;
  str = "acdbdca";
  cout << "Total palindrome substrings: "  << find_all_palindrome(str) << endl;
  str = "aaaaatyiueazbddbsxdeereed";
  cout << "Total palindrome substrings: "  << find_all_palindrome(str) << endl;
}
