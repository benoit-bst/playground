// C++ code for k largest elements in an array
#include <bits/stdc++.h>

using namespace std;

// time:  O(n*log(n))
// space: O(1)
void kLargest_sort(int arr[], int n, int k)
{
    // Sort the given array arr in reverse
    // order.
    sort(arr, arr + n, greater<int>());

    // Print the first kth largest elements
    for (int i = 0; i < k; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// time:  O(n k*log(n))
// space: O(n)
void kLargest_heap(int arr[], int n, int k)
{
    priority_queue<int> q;

    // fill heap
    for( int i = 0; i < n; ++i ) {
        q.push(arr[i]);
    }

    while( !q.empty() && k > 0) {
        cout << q.top() << ' ';
        q.pop();
        k--;
    }
    cout << endl;
}

// driver program
int main()
{
    int arr[] = { 1, 23, 12, 9, 30, 2, 50 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    kLargest_sort(arr, n, k); // 50 30 23
    kLargest_heap(arr, n, k); // 50 30 23
}
