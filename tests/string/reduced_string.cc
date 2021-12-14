//  https://www.hackerrank.com/challenges/reduced-string/problem
//
#include <bits/stdc++.h>

using namespace std;

string superReducedString(string s) {
    int len = s.size();
    string result = "";
    unordered_map<char, int>mp;
    for (int i = 0; i < len; i++)
        mp[s[i]]++;

    char letter;
    for (int i = 0; i < len; i++)
    {
        letter = s[i];
        if (mp[letter] % 2 != 0)
        {
            result += letter;
            mp[letter] = 0;
        }

    }
    if (result == "")
        return "Empty String";
    return result;
}

int main()
{
    string str = "more than ever";
    cout << superReducedString(str) << endl; // moethanv

    str = "abcdefghijkl";
    cout << superReducedString(str) << endl; // abcdefghijkl

    str = "aabbccdd";
    cout << superReducedString(str) << endl; // Empty String

    str = "aaabbbcccddd";
    cout << superReducedString(str) << endl; // abcd

    return 0;
}
