#include <bits/stdc++.h>

using namespace std;

// time:  O(N^2)
// space: O(1)
int largest_sum_1(vector<int> arr)
{
    int sum, msum = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        sum=0;
        for(int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            msum = max(msum, sum);
        }
    }
    return msum;
}

// Kadane’s Algorithm:
// time:  O(N)
// space: O(1)
int largest_sum(vector<int> arr)
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        max_ending_here = max_ending_here + arr[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;

}

int main()
{
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << largest_sum_1(arr) << endl; // 4 -1 -2 1 5 -> 7
    cout << largest_sum(arr) << endl; // 4 -1 -2 1 5 -> 7
}
