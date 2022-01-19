#include <bits/stdc++.h>

using namespace std;

// time  : O(N)
// space : O(C) where C is the lowercase alphabet size (26)
int longest_unique_sub_str(string s)
{
    unordered_map<char, int> seen;
    int max_length = 0;
    int start = 0;

    for (int end = 0; end < s.length(); ++end) {
        if (seen.find(s[end]) !=  seen.end()) {
            start = max(start, seen[s[end]] + 1);
        }
        seen[s[end]] = end;
        max_length = max(max_length, end-start + 1);

    }
    return max_length;
}

int main()
{
    string in = "geeksforgeeks";
    cout << longest_unique_sub_str(in) << endl; // 7

    in = "geeksforgeeks";
    cout << longest_unique_sub_str(in) << endl; // 7

    return 0;
}
