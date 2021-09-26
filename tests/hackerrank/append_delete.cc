#include <bits/stdc++.h>

#include <cmath>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'appendAndDelete' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. STRING t
 *  3. INTEGER k
 */

string appendAndDelete(string s, string t, int k) {

    int min = std::min(s.size(), t.size());
    int max = std::max(s.size(), t.size());
    int deep = 0;
    for (int i = 0; i < min; ++i) {
        if (s[i] != t[i]) {
            break;
        }
        deep++;
    }
    if (max == deep) {
        return "Yes";
    }

    int ret = s.size() - deep;
    int add = t.size() - deep;

    if ((ret + add) > k) {
        return  "No";
    } else {
        return "Yes";
    }
}

int main()
{
    // t is greater than s
    cout << appendAndDelete("abc", "abcre", 3) << endl; // Yes
    cout << appendAndDelete("abc", "abcrerr", 3) << endl; // No

    // same length
    cout << appendAndDelete("abc", "abc", 3) << endl; // Yes
    cout << appendAndDelete("a", "a", 3) << endl; // Yes

    // s is greater than t
    cout << appendAndDelete("abcre", "abc", 3) << endl; // Yes
    cout << appendAndDelete("abcretr", "abc", 3) << endl; // No
    cout << appendAndDelete("a", "ab", 2) << endl; // Yes
    cout << appendAndDelete("a", "ab", 1) << endl; // Yes
}
