#include <bits/stdc++.h>

using namespace std;

// O(N^2)
bool sum_of_two_values(vector<int> in, int sum) {

    int n = in.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (in[i] + in[j] == sum) {
                return true;
            }
        }
    }
    return false;
}

// O(N + log(N)) -> O(N)
bool sum_of_two_values_2(vector<int> in, int sum) {

    sort(in.begin(), in.end());

    int l_idx = 0;
    int r_idx = in.size() - 1;

    while (l_idx < r_idx) {
        if (in[l_idx] + in[r_idx] == sum) {
            return true;
        } else if (in[l_idx] + in[r_idx] < sum) {
            l_idx++;

        } else {
            r_idx--;
        }
    }
    return false;
}

int main()
{
    vector<int> in = { 1, 4, 45, 6, 10, -8 };
    int sum = 16;
    cout << sum_of_two_values(in, sum) << endl; // Yes
    cout << sum_of_two_values_2(in, sum) << endl; // Yes
    sum = 8;
    cout << sum_of_two_values(in, sum) << endl; // No
    cout << sum_of_two_values_2(in, sum) << endl; // No

    return 0;
}
