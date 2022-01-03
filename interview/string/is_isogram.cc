// C++ program to check whether two strings are anagrams
// of each other
//
#include <bits/stdc++.h>

using namespace std;

const int NO_OF_CHARS = 26;

// time O(N*logN + N) -> O(N*logN)
// O(1)
bool is_isogram(string str)
{
    sort(str.begin(), str.end());

    for(int i = 0; i < str.size() - 1; i++)
    {
        if(str[i] == str[i+1])
            return false;
    }
    return true;
}

// time O(N)
// O(N)
bool fast_is_isogram(string str)
{
    unordered_map<char, int> freq;

    for(int i =0; i < str.size(); i++)
    {
    	auto it = freq.find(str[i]);
    	if(it == freq.end()) {
            freq[str[i]] = 1;
    	} else  {
			return false;
    	}
    }
    return true;
}

// Driver code
int main()
{
    string str = "test";
    cout << "Is isogram " << is_isogram(str) << endl;
    cout << "Is isogram " << fast_is_isogram(str) << endl;

    str = "tesr";
    cout << "Is isogram " << is_isogram(str) << endl;
    cout << "Is isogram " << fast_is_isogram(str) << endl;
    return 0;
}
