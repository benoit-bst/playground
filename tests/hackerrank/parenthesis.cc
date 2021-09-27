#include <atomic>
#include <iostream>
#include <vector>
#include <stack>


/*

 isWellParenthesized

 Input: "(()()())"
 Input: "()(()(()))()", Output: True

 Input ")(", Output: False
      "(((", "))("
*/

using namespace std;

bool isWellParenthesized(string word) {

  // (())
  vector<bool> buff;
  buff.resize(word.length());
  for (auto val : buff) {
    val = false;
  }
  for (int i = 0; i < word.size(); ++i){

       if (word[i] == '(' && buff[i] != true) {
         buff[i] = true;

          for (int j = i + 1; j < word.size(); ++j){
              if (word[j] == ')' && buff[j] == false) {
                buff[j] = true;
                break;
              }
          }
       }
  }

  for (auto val : buff) {
    if (val == false) {
      return false;
    }
  }
  return true;

}

bool isWellParenthesized_2(string word) {

    stack<char> s;
    for (int i = 0; i < word.size(); ++i) {
        if (word[i] == '(') {
            s.push(word[i]);
        }
        if (word[i] == ')') {
            if (s.empty() || (s.top() == ')'))
                return false;
            else
                s.pop();
        }
    }

    return s.empty() ? true: false;
}

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

// To execute C++, please define "int main()"
int main() {
  string words = "()())";
  cout << isWellParenthesized(words) << endl;
  cout << isWellParenthesized_2(words) << endl;

  words = "(()())";
  cout << isWellParenthesized(words) << endl;
  cout << isWellParenthesized_2(words) << endl;

  words = ")()()";
  cout << isWellParenthesized(words) << endl;
  cout << isWellParenthesized_2(words) << endl;

  words = ")(";
  cout << isWellParenthesized(words) << endl;
  cout << isWellParenthesized_2(words) << endl;

  words = ")";
  cout << isWellParenthesized(words) << endl;
  cout << isWellParenthesized_2(words) << endl;

  words = "()";
  cout << isWellParenthesized(words) << endl;
  cout << isWellParenthesized_2(words) << endl;

  return 0;
}

