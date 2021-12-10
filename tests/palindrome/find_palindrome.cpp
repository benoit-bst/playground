#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <unordered_set>

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



// Expand in both directions of `low` and `high` to find all palindromes
void expand(string str, int low, int high, unordered_set<string> &set)
{
    // run till `str[low.high]` is not a palindrome
    while (low >= 0 && high < str.length() && str[low] == str[high])
    {
        // push all palindromes into a set
        auto sub = str.substr(low, high - low + 1);
        if (sub.length() > 1) {
            set.insert(str.substr(low, high - low + 1));
        }

        // Expand in both directions
        low--, high++;
    }
}
// O(N*N/2) -> O(N^2)
void findPalindromicSubstrings(string str)
{
    // create an empty set to store all unique palindromic substrings
    unordered_set<string> set;

    for (int i = 0; i < str.length(); i++)
    {
        // find all odd length palindrome with `str[i]` as a midpoint
        expand(str, i, i, set);

        // find all even length palindrome with `str[i]` and `str[i+1]` as
        // its midpoints
        expand(str, i, i + 1, set);
    }

    // print all unique palindromic substrings
    for (auto i: set) {
        cout << i << " ";
    }
}

int main() {
  string str = "aa";
  cout << "first method "  << find_all_palindrome(str) << endl;
  cout << "new method   "; findPalindromicSubstrings(str); cout << endl;
  str = "aab";
  cout << "Total palindrome substrings: "  << find_all_palindrome(str) << endl;
  cout << "new method   "; findPalindromicSubstrings(str); cout << endl;
  str = "aabbbaa";
  cout << "Total palindrome substrings: "  << find_all_palindrome(str) << endl;
  cout << "new method   "; findPalindromicSubstrings(str); cout << endl;
  str = "aabaa";
  cout << "Total palindrome substrings: "  << find_all_palindrome(str) << endl;
  cout << "new method   "; findPalindromicSubstrings(str); cout << endl;
  str = "acdbdca";
  cout << "Total palindrome substrings: "  << find_all_palindrome(str) << endl;
  cout << "new method   "; findPalindromicSubstrings(str); cout << endl;
  str = "aaaaatyiueazbddbsxdeereed";
  cout << "Total palindrome substrings: "  << find_all_palindrome(str) << endl;
  cout << "new method   "; findPalindromicSubstrings(str); cout << endl;
 }
