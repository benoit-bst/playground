#include <bits/stdc++.h>

using namespace std;

int nonDivisibleSubset(int k, vector<int> s) {

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


// g++ -std=c++11 Non-Divisible_Subset.cc
int main()
{
    std::vector<int> input = {3, 7, 2, 9, 1};
    int k = 3;
    cout << nonDivisibleSubset(k, input) << endl;
    input = {2, 2, 2, 2, 2};
    cout << nonDivisibleSubset(k, input) << endl;
    input = {3, 3, 3, 3, 3};
    cout << nonDivisibleSubset(k, input) << endl;
    input = {1, 7, 2, 4};
    k = 2;
    cout << nonDivisibleSubset(k, input) << endl;
    return 0;
}
