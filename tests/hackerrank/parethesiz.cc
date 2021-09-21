#include <iostream>
#include <vector>


/*

 isWellParenthesized

 Input: "(()()())"
 Input: "()(()(()))()", Output: True

 Input ")(", Output: False
      "(((", "))("

sorry I lost my connection okay
are you here ?

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

// To execute C++, please define "int main()"
int main() {
  string words = "()())";
  cout << isWellParenthesized(words) << endl;

  words = "(()())";
  cout << isWellParenthesized(words) << endl;

  words = ")()()";
  cout << isWellParenthesized(words) << endl;

  words = ")(";
  cout << isWellParenthesized(words) << endl;

  words = ")";
  cout << isWellParenthesized(words) << endl;

  words = "()";
  cout << isWellParenthesized(words) << endl;

  return 0;
}

