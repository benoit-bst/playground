#include <bits/stdc++.h>
using namespace std;

// time: O(N*log(N))
// space: O(1)
void segregate0and1_sort(int arr[], int n)
{
    sort(arr, arr + n);
}

// time: O(2*N)
// space: O(1)
void segregate0and1(int arr[], int n)
{
    int count = 0; // Counts the no of zeros in arr

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            count++;
    }

    // Loop fills the arr with 0 until count
    for (int i = 0; i < count; i++)
        arr[i] = 0;

    // Loop fills remaining arr space with 1
    for (int i = count; i < n; i++)
        arr[i] = 1;
}

// time: O(N)
// space: O(1)
void segregate0and1_fast(int arr[],
                    int size)
{
    int type0 = 0;
    int type1 = size - 1;

    while(type0 < type1)
    {
        if(arr[type0] == 1)
        {
            swap(arr[type0],
                 arr[type1]);
            type1--;
        }
        else
        type0++;
    }
}

void print(int arr[], int n)
{
    cout << "Array after segregation is ";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver function
int main()
{
    {
        int arr[] = { 0, 1, 0, 1, 1, 1 };
        int n = sizeof(arr) / sizeof(arr[0]);

        segregate0and1_sort(arr, n);
        print(arr, n);
    }
    {
        int arr[] = { 0, 1, 0, 1, 1, 1 };
        int n = sizeof(arr) / sizeof(arr[0]);

        segregate0and1(arr, n);
        print(arr, n);
    }
    {
        int arr[] = { 0, 1, 0, 1, 1, 1 };
        int n = sizeof(arr) / sizeof(arr[0]);

        segregate0and1_fast(arr, n);
        print(arr, n);
    }
    return 0;
}
