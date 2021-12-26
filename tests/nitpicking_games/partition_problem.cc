#include <bits/stdc++.h>

using namespace std;

// Partition problem is to determine whether a given set can be
// partitioned into two subsets such that the sum of elements
// in both subsets is the same.

// A utility function that returns true if there is
// a subset of arr[] with sun equal to given sum
bool isSubsetSum(vector<int>& arr, int n, int sum)
{
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;

    // If last element is greater than sum, then
    // ignore it
    if (arr[n - 1] > sum)
        return isSubsetSum(arr, n - 1, sum);

    /* else, check if sum can be obtained by any of
        the following
        (a) including the last element
        (b) excluding the last element
    */
    return isSubsetSum(arr, n - 1, sum)
           || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}

// O(2^N)
// O(1)
bool findPartition(vector<int>& arr)
{
    // sum
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
        sum += arr[i];

    // If sum is odd, there cannot be two subsets
    // with equal sum
    if (sum % 2 != 0)
        return false;

    // Find if there is subset with sum equal to
    // half of total sum
    return isSubsetSum(arr, arr.size(), sum / 2);
}

// The time complexity is O(M.N) and the space rquirement is O(N)
// where N is the sum of all numbers divided by two.
//
// dp[j] = dp[j]||dp[j-c]
bool canPartition(vector<int>& nums) {
    int totalSum = std::accumulate(begin(nums), end(nums), 0, [](auto &a, auto &b) {
        return a + b;
    });

    // If sum is odd, there cannot be two subsets
    // with equal sum
    if (totalSum & 1) return false;

    int half = totalSum >> 1;

    int n = nums.size();
    vector<bool> dp(half + 1, false);
    dp[0] = true;

    for (auto curr : nums) {
        for (int j = half; j >= curr; j--) {
            dp[j] = dp[j] || dp[j - curr];
        }
    }
    return dp[half];
}

int main()
{
    std::vector<int> input = {1, 5, 11, 5};
    cout << findPartition(input) << endl;   // true
    cout << canPartition(input) << endl;    // true

    input = {3, 7, 2};
    cout << findPartition(input) << endl;   // false
    cout << canPartition(input) << endl;    // false

    return 0;
}
