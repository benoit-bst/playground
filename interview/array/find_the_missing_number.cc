
#include <bits/stdc++.h>

using namespace std;

// time : O(2*N)
// space: O(N)
int find_the_missing_number_counting(vector<int> arr)
{
    if (arr.size() == 0) {
        return -1;
    }

    vector<int> counting(arr.size() + 1, 0);
    for (int i = 0; i < arr.size(); i++) {
        counting[arr[i] - 1]++;
    }

    for (int i = 0; i < arr.size(); i++) {
        if (counting[i] == 0) {
            return i + 1;
        }
    }
    return -1;
}

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
    vector<int> arr = { 1, 3, 5, 4};
    cout << find_the_missing_number_counting(arr) << endl; // 2
    cout << endl;

    arr = { 3, 4, 9, 8, 7, 1, 2, 6};
    cout << find_the_missing_number_counting(arr) << endl; // 5
    cout << endl;

    arr = { 3, 4, 9, 8, 7, 1, 2, 6};
    cout << find_the_missing_number(arr) << endl; // 5

    return 0;
}

