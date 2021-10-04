#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */

long nb_a_inside_pattern(const string& s, const long n) {
    long nb_a_into_pattern = 0;
    for (long i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            nb_a_into_pattern++;
        }
    }
    return nb_a_into_pattern;
}

long repeatedString(string s, long n) {

    // edge cases
    if (s.size() == 1 && s[0] == 'a')
        return n;
    if (s.size() == 1 && s[0] != 'a')
        return 0;

    // we know the pattern
    if (n < s.size()) {
        return nb_a_inside_pattern(s, n) ;
    }
    long nb_a_into_pattern = nb_a_inside_pattern(s, s.size()) ;
    // general case
    long remaining = n % s.size();
    long nb_sub_string = n / s.size();

    if (remaining == 0) {
        return nb_sub_string*nb_a_into_pattern;
    }
    else {
        long result = nb_sub_string*nb_a_into_pattern;
        nb_a_into_pattern = 0;
        for (long i = 0; i < remaining; ++i) {
            if (s[i] == 'a') {
                nb_a_into_pattern++;
            }
        }
        return result + nb_a_into_pattern;
    }

}

// g++ -std=c++11 Repeated_String.cc
int main()
{
    string pattern = "aba";
    long nb = 10;
    cout << repeatedString(pattern, nb) << endl;


}
