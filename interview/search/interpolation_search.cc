#include <iostream>
using namespace std;

/*
The Interpolation Search is an improvement over Binary Search
for instances, where the values in a sorted array are
uniformly distributed. Binary Search always goes
to the middle element to check. On the other hand,
interpolation search may go to different locations according to
the value of the key being searched.
For example, if the value of the key is closer to the last element,
interpolation search is likely to start search toward
the end side
*/


// If the data set is sorted and uniformly distributed,
// the average case time complexity of Interpolation Search is
// O(log_2(log(N))
// where N is the total number of elements in the array
// space : O(1)
int interpolationSearch(int arr[], int lo, int hi, int x)
{
    int pos;

    // Since array is sorted, an element present
    // in array must be in range defined by corner
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {

        // Probing the position with keeping
        // uniform distribution in mind.
        pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));

        // Condition of target found
        if (arr[pos] == x)
            return pos;

        // If x is larger, x is in right sub array
        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, hi, x);

        // If x is smaller, x is in left sub array
        if (arr[pos] > x)
            return interpolationSearch(arr, lo, pos - 1, x);
    }
    return -1;
}


int main()
{
    int arr[] = { 10, 12, 13, 16, 18, 19, 20, 21,
                  22, 23, 24, 33, 35, 42, 47 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int x = 13;
    cout << "index : " << interpolationSearch(arr, 0, n - 1, x) << endl; // 2
}
