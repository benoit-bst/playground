#include <bits/stdc++.h>

using namespace std;

// time : O(N^2)
// space : O(1)
int max_water_volume(vector<int> arr)
{
    // To store the maximum water
    // that can be stored
    int water_volume = 0;

    // For every element of the array
    for (int i = 1; i < arr.size() - 1; i++) {

        // Find the maximum element on its left
        int left = arr[i];
        for (int j = 0; j < i; j++) {
           left = max(left, arr[j]);
        }

        // Find the maximum element on its right
        int right = arr[i];
        for (int j= i + 1; j < arr.size(); j++) {
           right = max(right, arr[j]);
        }

       // Update the maximum water
       water_volume += (min(left, right) - arr[i]);
    }

    return water_volume;
}

// time : O(N)
// space : O(1)
int findWater(vector<int> arr)
{
    // initialize output
    int result = 0;

    // maximum element on left and right
    int left_max = 0, right_max = 0;

    // indices to traverse the array
    int lo = 0, hi = arr.size() - 1;

    while (lo <= hi) {

        if (arr[lo] < arr[hi]) {
            if (arr[lo] > left_max)
                // update max in left
                left_max = arr[lo];
            else
                // water on curr element = max - curr
                result += left_max - arr[lo];
            lo++;
        }
        else {
            if (arr[hi] > right_max)
                // update right maximum
                right_max = arr[hi];
            else
                result += right_max - arr[hi];
            hi--;
        }
    }

    return result;
}

int main()
{
    vector<int> in = {0, 2, 0, 2, 0};
    cout << max_water_volume(in) << endl; // 2
    cout << findWater(in) << endl; // 2

    in = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << max_water_volume(in) << endl; // 6
    cout << findWater(in) << endl; // 6

    return 0;
}
