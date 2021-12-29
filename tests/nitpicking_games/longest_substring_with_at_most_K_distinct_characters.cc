#include <bits/stdc++.h>

using namespace std;

// time  : O(N)
// space : O(C) qhere C is the lowercase alphabet size (26)
int lengthOfLongestSubstringKDistinct(string s, int k) {
    int longest = 0, start = 0, distinct_count = 0;
    array<int, 256> visited = {0};
    for (int i = 0; i < s.length(); ++i) {
        if (visited[s[i]] == 0) {
            ++distinct_count;
        }
        ++visited[s[i]];
        while (distinct_count > k) {
            --visited[s[start]];
            if (visited[s[start]] == 0) {
                --distinct_count;
            }
            ++start;
        }
        longest = max(longest, i - start + 1);
    }
    return longest;
}

int main()
{
    string in = "eceba";
    int k = 2;
    cout << lengthOfLongestSubstringKDistinct(in, k) << endl; // 3 - ece

    in = "aabbcc";
    k = 1;
    cout << lengthOfLongestSubstringKDistinct(in, k) << endl; // 2 - {"aa" , "bb" , "cc"}

    in = "aabbcc";
    k = 2;
    cout << lengthOfLongestSubstringKDistinct(in, k) << endl; // 4 - {"aabb" , "bbcc"}.

    in = "aabbcc";
    k = 3;
    cout << lengthOfLongestSubstringKDistinct(in, k) << endl; // 6 - {"aabbcc" , "abbcc" , "aabbc" , "abbc" }

    return 0;
}
