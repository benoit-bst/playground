#include <bits/stdc++.h>

using namespace std;

int nonDivisibleSubset(int k, vector<int> s) {

    set<int> f;

    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); ++j) {
            if (((s[i] + s[j]) % k) != 0) {
                if (s[i] % k != 0) {
                    f.insert(s[i]);
                }
                if (s[j] % k != 0) {
                    f.insert(s[j]);
                }
            }
        }
    }
    return f.size();
}

int nonDivisibleSubset_2(int k, vector<int> s) {

    vector<int> f;
    f.resize(k);

    // Fill frequency array with values modulo K
    for (int i = 0; i < s.size(); i++)
        f[s[i] % k]++;

    //  if K is even, then update f[K/2]
    if (k % 2 == 0)
        f[k/2] = min(f[k/2], 1);

    // Initialize result by minimum of 1 or
    // count of numbers giving remainder 0
    int res = min(f[0], 1);

    // Choose maximum of count of numbers
    // giving remainder i or K-i
    for (int i = 1; i <= k/2; i++)
        res += max(f[i], f[k-i]);

    return res;
}

// https://medium.com/@mrunankmistry52/non-divisible-subset-problem-comprehensive-explanation-c878a752f057
// g++ -std=c++11 Non-Divisible_Subset.cc
int main()
{
    std::vector<int> input = {3, 7, 2, 9, 1};
    int k = 3;
    cout << nonDivisibleSubset(k, input) << endl;
    cout << nonDivisibleSubset_2(k, input) << endl;
    cout << "-------------" << endl;
    input = {2, 2, 2, 2, 2};
    cout << nonDivisibleSubset(k, input) << endl;
    cout << nonDivisibleSubset_2(k, input) << endl;
    cout << "-------------" << endl;
    input = {3, 3, 3, 3, 3};
    cout << nonDivisibleSubset(k, input) << endl;
    cout << nonDivisibleSubset_2(k, input) << endl;
    cout << "-------------" << endl;
    input = {1, 7, 2, 4};
    k = 3;
    cout << nonDivisibleSubset(k, input) << endl;
    cout << nonDivisibleSubset_2(k, input) << endl;
    cout << "-------------" << endl;
    input = {278, 576, 496, 727, 410, 124, 338, 149, 209, 702, 282, 718, 771, 575, 436};
    k = 7;
    cout << nonDivisibleSubset(k, input) << endl;
    cout << nonDivisibleSubset_2(k, input) << endl;
    return 0;
}
