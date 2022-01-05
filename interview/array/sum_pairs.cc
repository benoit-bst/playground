#include <bits/stdc++.h>

using namespace std;

// O(N^2)
// O(1)
bool sum_pairs(int sum, vector<int>& s) {

    int n = s.size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if((s[i] + s[j]) == sum) {
               return true;
            }
        }
    }
    return false;
}

// O(N*log(N) + N) -> O(N*log(N))
// O(1)
bool sum_pairs_with_sort(int sum, vector<int>& s) {
    int l, r;

    /* Sort the elements */
    sort(s.begin(), s.end());

    /* Now look for the two candidates in
       the sorted array*/
    l = 0;
    r = s.size() - 1;
    while (l < r) {
        if (s[l] + s[r] == sum)
            return true;
        else if (s[l] + s[r] < sum)
            l++;
        else // A[i] + A[j] > sum
            r--;
    }
    return false;
}

// O(N)
// O(N)
bool sum_pairs_with_hash(int sum, vector<int>& s)
{
    unordered_set<int> h;
    for (int i = 0; i < s.size(); i++)
    {
        int temp = sum - s[i];

        if (h.find(temp) != h.end()) {
            return true;
        }

        h.insert(s[i]);
    }
    return false;
}

int main()
{
    std::vector<int> input = {3, 7, 2, 9, 1};
    int k = 10;
    cout << sum_pairs(k, input) << endl;             // 1
    cout << sum_pairs_with_sort(k, input) << endl;   // 1
    cout << sum_pairs_with_hash(k, input) << endl;   // 1

    input = {3, 7, 2};
    k = 6;
    cout << sum_pairs(k, input) << endl;             // 0
    cout << sum_pairs_with_sort(k, input) << endl;   // 0
    cout << sum_pairs_with_hash(k, input) << endl;   // 0

    return 0;
}
