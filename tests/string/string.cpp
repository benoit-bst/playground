#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

// time complexity O(N)
// space complexity O(1)
bool checker(const string& input, const char open_delimiter, char close_delimiter) {
    int count = 0;
    for (auto& ch : input) {
        if (ch == open_delimiter) {
            count++;
        } else if (ch == close_delimiter) {
            if (count == 0) {
                return false;
            }
            count--;
        }
    }
    if (count != 0){
        return false;
    }
    return true;
}

// time complexity O(N*3)
// space complexity O(1)
const int MAX_SIZE = 999999;
bool check_syntax(const string& input) {

    if (input.size() > MAX_SIZE) {
        std::cerr << "out of range";
        return false;
    }
    return checker(input, '(', ')') && checker(input, '[', ']') && checker(input, '{', '}');
}

// g++ -std=c++11 string.cpp
int main() {
  string str = "aa(())";
  cout << "check syntax: "  << check_syntax(str) << endl;
  str = "aa(()";
  cout << "check syntax: "  << check_syntax(str) << endl;
  str = "aa))";
  cout << "check syntax: "  << check_syntax(str) << endl;
  str = "aa{[(])}";
  cout << "check syntax: "  << check_syntax(str) << endl;
  str = "aa{[])}";
  cout << "check syntax: "  << check_syntax(str) << endl;
  // Edge case - what do we want ? empty string is allowed or not ?
  str = "";
  cout << "check syntax: "  << check_syntax(str) << endl;
  // What is the max size of the input
}
