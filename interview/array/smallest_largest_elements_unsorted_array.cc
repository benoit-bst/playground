#include <bits/stdc++.h>

using namespace std;

// time : O(N*logN)
// space: O(1)
void smallest_largest_elem_sort(vector<int> arr)
{
    if (arr.size() == 0) {
        return;
    }

    sort(arr.begin(), arr.end());

    cout << "first  : " << *arr.begin() << endl;
    cout << "second : " << arr[arr.size() - 1] << endl;
}

// time : O(N)
// space: O(1)
void smallest_largest_elem(vector<int> arr)
{
    int smallest = arr[0];
    int largest = arr[0];

    for (auto _val : arr) {
        if (_val < smallest) {
            smallest = _val;
        }
        if (_val > largest) {
            largest = _val;
        }
    }

    cout << "first  : " << smallest << endl;
    cout << "second : " << largest << endl;
}


int main()
{
    vector<int> arr = { 5, 2, 7, 2, 9, 3, 4, 7, 8, 8 };
    smallest_largest_elem_sort(arr); // 2, 9
    smallest_largest_elem(arr); // 2, 9

    return 0;
}

