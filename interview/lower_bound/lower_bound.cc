#include <bits/stdc++.h>
using namespace std;

// Function to implement lower_bound
// divide and conquer paradigm
// time  : O(log(N))
// space : O(1)
int my_lower_bound(vector<int> arr, int X)
{
    int N = arr.size();
    int mid;

    // Initialise starting index and
    // ending index
    int low = 0;
    int high = N;

    // Till low is less than high
    while (low < high) {
        mid = low + (high - low) / 2;

        // If X is less than or equal
        // to arr[mid], then find in
        // left subarray
        if (X <= arr[mid]) {
            high = mid;
        }

        // If X is greater arr[mid]
        // then find in right subarray
        else {
            low = mid + 1;
        }
    }

    // if X is greater than arr[n-1]
    if(low < N && arr[low] < X) {
       low++;
    }

    // Return the lower_bound index
    return low;
}

// Time complexity : log(N)
int main()
{
    vector<int> a = { 10, 20, 30, 30, 40, 50 };
    cout << (lower_bound(a.begin(), a.end(), 30) - a.begin()) << endl; // 2
    cout << my_lower_bound(a, 30) << endl; // 2

    a = { 10, 22, 9, 33, 21, 50, 41, 60 };
    cout << (lower_bound(a.begin(), a.end(), 30) - a.begin()) << endl; // 5
    cout << my_lower_bound(a, 30) << endl; // 2

    a = { 3, 5 };
    cout << *lower_bound(a.begin(), a.end(), 5) << endl; // 5
    cout << my_lower_bound(a, 5) << endl; // 1

    a = { 3 };
    cout << *lower_bound(a.begin(), a.end(), 5) << endl; // 5
    cout << my_lower_bound(a, 5) << endl; // 1

    a = { 3, 10 };
    cout << *lower_bound(a.begin(), a.end(), 2) << endl; // 3
}
