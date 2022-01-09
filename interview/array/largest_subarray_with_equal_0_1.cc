#include <bits/stdc++.h>

using namespace std;

// This function Prints the starting and ending
// indexes of the largest subarray with equal
// number of 0s and 1s. Also returns the size
// of such subarray.

// time: O(N^2)
// space: O(1)
int findSubArray(int arr[], int n)
{
    int sum = 0;
    int maxsize = -1, startindex;

    // Pick a starting point as i
    for (int i = 0; i < n - 1; i++) {
        sum = (arr[i] == 0) ? -1 : 1;

        // Consider all subarrays starting from i
        for (int j = i + 1; j < n; j++) {
            (arr[j] == 0) ? (sum += -1) : (sum += 1);

            // If this is a 0 sum subarray, then
            // compare it with maximum size subarray
            // calculated so far
            if (sum == 0 && maxsize < j - i + 1) {
                maxsize = j - i + 1;
                startindex = i;
            }
        }
    }
    if (maxsize == -1)
        cout << "No such subarray";
    else
        cout << startindex << " to "
             << startindex + maxsize - 1;
    cout << endl;

    return maxsize;
}

// time: O(N)
// space: O(N)
int maxLen(int arr[], int n)
{
    // Creates an empty hashMap hM

    unordered_map<int, int> hM;

    int sum = 0; // Initialize sum of elements
    int max_len = 0; // Initialize result
    int ending_index = -1;

    for (int i = 0; i < n; i++)
        arr[i] = (arr[i] == 0) ? -1 : 1;

    // Traverse through the given array

    for (int i = 0; i < n; i++) {
        // Add current element to sum

        sum += arr[i];

        // To handle sum=0 at last index

        if (sum == 0) {
            max_len = i + 1;
            ending_index = i;
        }

        // If this sum is seen before, then update max_len
        // if required

        if (hM.find(sum) != hM.end()) {
            if (max_len < i - hM[sum]) {
                max_len = i - hM[sum];
                ending_index = i;
            }
        }
        else // Else put this sum in hash table
            hM[sum] = i;
    }

    for (int i = 0; i < n; i++)
        arr[i] = (arr[i] == -1) ? 0 : 1;

    printf("%d to %d\n",
           ending_index - max_len + 1, ending_index);

    return max_len;
}

int main()
{
    {
        int arr[] = { 1, 0, 0, 1, 0, 1, 1 };
        int size = sizeof(arr) / sizeof(arr[0]);

        cout << findSubArray(arr, size) << endl; // 0 to 5 -> 6
        cout << maxLen(arr, size) << endl; // 0 to 5 -> 6
    }
    {
        int arr[] = { 0, 0, 0, 1, 0, 1, 1 }; // 1 to 6 -> 6
        int size = sizeof(arr) / sizeof(arr[0]); // 1 to 6 -> 6

        cout << findSubArray(arr, size) << endl;
        cout << maxLen(arr, size) << endl;
    }
    {
        int arr[] = { 0, 1, 0, 1, 1 }; // 0 to 3 -> 4
        int size = sizeof(arr) / sizeof(arr[0]); // 0 to 3 -> 4

        cout << findSubArray(arr, size) << endl;
        cout << maxLen(arr, size) << endl;
    }

    return 0;
}
