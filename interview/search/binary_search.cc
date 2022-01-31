#include <iostream>
using namespace std;

// time : O(log(n))
// space : O(log(n)) because of the stack
int binarySearch(int array[], int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (array[mid] == x)
      return mid;

    // Search the left half
    if (array[mid] > x)
      return binarySearch(array, x, low, mid - 1);

    // Search the right half
    return binarySearch(array, x, mid + 1, high);
  }

  return -1;
}

// time : O(log(n))
// space : O(1)
int iterative_binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was
    // not present
    return -1;
}

int main()
{
    int arr[] = { 10, 12, 13, 16, 18, 19, 20, 21,
                  22, 23, 24, 33, 35, 42, 47 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int x = 13;
    cout << "index : " << binarySearch(arr, x, 0, n -1) << endl; // 2
    cout << "index : " << iterative_binarySearch(arr, 0, n -1, x) << endl; // 2
}
