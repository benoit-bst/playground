#include <bits/stdc++.h>
#define NO_OF_CHARS 256

using namespace std;

// time:  O(2*N) N the length of string
// space: O(C) C the length ot alphabet
void firstNonRepeatingChar(string& s)
{
  vector<int> count(NO_OF_CHARS, 0);

  for(int i = 0; i < s.length(); i++) {
      count[s[i]]++; //increment the count of each character by using ASCII of character as key
  }
  for(int i = 0; i < s.length(); i++) {
      if(count[s[i]] == 1) // if count is 1, then print and break
      {
          cout<<s[i]<<" is the first non-repeating character "<<endl;
          break;
      }
  }
}

//Here position is the first occurence of that character
struct countposition
{
  int count;
  int position;
};

// time:  O(2*N) N the length of string
// space: O(C) C the length ot alphabet
void firstNonRepeatingChar2(string& s)
{
  int res = INT_MAX;
  vector<countposition> count(NO_OF_CHARS);

  for(int i = 0; i < s.length(); i++) {

    (count[s[i]].count)++; // increment the count of each character by using ASCII of character as key
    // storing the position of the first occurencce
    if (count[s[i]].count == 1)
    {
      count[s[i]].position = i;
    }
  }
  // In count array, if count is 1 and position is least then update
  for(int i=0; i < NO_OF_CHARS; i++) {
    if(count[i].count == 1 && res > count[i].position) // if count is 1, then print and break
    {
      res = count[i].position;
    }
  }
  cout<<s[res]<<" is the first non-repeating character "<<endl;
}

int main()
{
  string s = "tutorial cup";
  cout<<"Input string is: " << s << endl;
  firstNonRepeatingChar(s);  // o
  firstNonRepeatingChar2(s); // o
}
