// C++ program to check whether two strings are anagrams
// of each other
#include <bits/stdc++.h>
using namespace std;
const int NO_OF_CHARS = 26;

/* function to check whether two strings are anagram of
each other */
// O(2*N*LOG(N) + N) -> O(N*LOG(N))
// O()
bool areAnagram(string str1, string str2)
{
    // Get lengths of both strings
    int n1 = str1.length();
    int n2 = str2.length();

    // If length of both strings is not same, then they
    // cannot be anagram
    if (n1 != n2)
        return false;

    // Sort both the strings
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // Compare sorted strings
    for (int i = 0; i < n1; i++)
        if (str1[i] != str2[i])
            return false;

    return true;
}

bool areAnagram1(string str1, string str2)
{
    // Get lengths of both strings
    int n1 = str1.length();
    int n2 = str2.length();

    // If length of both strings is not same, then they
    // cannot be anagram
    if (n1 != n2)
        return false;

    // Create a count array and initialize all values as 0
    int count[NO_OF_CHARS] = { 0 };

    // For each character in input strings, increment count
    // in the corresponding count array
    for (int i = 0; i < n1; i++) {
        count[str1[i]-'a']++;
        count[str2[i]-'a']--;
    }

    // See if there is any non-zero value in count array
    for (int i = 0; i < NO_OF_CHARS; i++)
        if (count[i])
            return false;
    return true;
}

// Driver code
int main()
{
    string str1 = "test";
    string str2 = "ttew";

    // Function Call
    if (areAnagram(str1, str2))
        cout << "The two strings are anagram of each other" << endl;
    else
        cout << "The two strings are not anagram of each "
                "other" << endl;
    if (areAnagram1(str1, str2))
        cout << "The two strings are anagram of each other" << endl;
    else
        cout << "The two strings are not anagram of each "
                "other" << endl;

    str1 = "test";
    str2 = "ttes";

    // Function Call
    if (areAnagram(str1, str2))
        cout << "The two strings are anagram of each other" << endl;
    else
        cout << "The two strings are not anagram of each "
                "other" << endl;
    if (areAnagram1(str1, str2))
        cout << "The two strings are anagram of each other" << endl;
    else
        cout << "The two strings are not anagram of each "
                "other" << endl;

    return 0;
}
