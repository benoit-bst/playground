#include <bits/stdc++.h>

using namespace std;

// O(N^2)
// O(1)
int divisible_sum_pairs(int k, vector<int>& s) {

    int count = 0;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if((s[i] + s[j]) % k == 0) {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    std::vector<int> input = {3, 7, 2, 9, 1};
    int k = 3;
    cout << divisible_sum_pairs(k, input) << endl;   // 3 + 9, 7 + 2, 2 + 1

    input = {3, 7, 2};
    k = 2;
    cout << divisible_sum_pairs(k, input) << endl;   // 7 + 3

    return 0;
}
