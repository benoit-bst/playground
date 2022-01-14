#include <bits/stdc++.h>

using namespace std;

// time : O(N)
// space : O(1)
vector<int> findPeak(int arr[], int n)
{
    vector<int> res;

    // first or last element is peak element
    if (n == 1)
      return res;

    // check for every other element
    for (int i = 1; i < n - 1; i++) {

        // check if the neighbors are smaller
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            res.push_back(i);
    }
    return res;
}


// A binary search based function
// that returns index of a peak element
int findPeakUtil(int arr[], int low,
                 int high, int n)
{
    // Find index of middle element
    // (low + high)/2
    int mid = low + (high - low) / 2;

    // Compare middle element with its
    // neighbours (if neighbours exist)
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&
        (mid == n - 1 || arr[mid + 1] <= arr[mid]))
        return mid;

    // If middle element is not peak and its
    // left neighbour is greater than it,
    // then left half must have a peak element
    else if (mid > 0 && arr[mid - 1] > arr[mid])
        return findPeakUtil(arr, low, (mid - 1), n);

    // If middle element is not peak and its
    // right neighbour is greater than it,
    // then right half must have a peak element
    else
        return findPeakUtil(
            arr, (mid + 1), high, n);
}

// time : O(log(N))
// space : O(1)
// A wrapper over recursive function findPeakUtil()
int fast_findPeak(int arr[], int n)
{
    return findPeakUtil(arr, 0, n - 1, n);
}

// Driver Code
int main()
{
    {
        int arr[] = { 1, 3, 20, 4, 1, 0 };
        int n = sizeof(arr) / sizeof(arr[0]);
        auto res = findPeak(arr, n);
        for (auto& _val : res) {
            cout << _val << " " << endl; // 2
        }
        cout <<  fast_findPeak(arr, n) << endl; // 2
    }
    {
        int arr[] = { 1, 3, 20, 4, 1, 0, 1, 10, 3};
        int n = sizeof(arr) / sizeof(arr[0]);
        auto res = findPeak(arr, n);
        for (auto& _val : res) {
            cout << _val << " " << endl; // 2 - 7
        }
    }

    return 0;
}
