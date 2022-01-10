
#include <bits/stdc++.h>

using namespace std;

// formula series :
// Calculate the sum of first n natural numbers as sumtotal= n*(n+1)/2
// time : O(N)
// space: O(1)
int find_the_missing_number(vector<int> arr)
{
    if (arr.size() == 0) {
        return -1;
    }

    int total = (arr.size() + 1) * (arr.size() + 2) / 2;
    for (int i = 0; i < arr.size(); i++)
        total -= arr[i];
    return total;
}

int main()
{
    vector<int> arr = { 3, 4, 9, 8, 7, 1, 2, 6};
    cout << find_the_missing_number(arr) << endl; // 5

    return 0;
}

