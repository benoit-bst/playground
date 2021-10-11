// C++ program to find first and last occurrence of
// an elements in given sorted array
#include <bits/stdc++.h>
using namespace std;

// Function for finding first and last occurrence
// of an elements
void findFirstAndLast(vector<int> arr, int x)
{
    int n = arr.size();
    int first = -1, last = -1;
    for (int i = 0; i < n; i++) {
        if (x != arr[i])
            continue;
        if (first == -1)
            first = i;
        last = i;
    }
    if (first != -1) {
        cout << "First Occurrence = " << first << endl;
        cout << "Last Occurrence = " << last << endl;
    } else {
        cout << "Not Found";
    }
}

// Driver code
int main()
{
    vector<int> arr = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
    int x = 2;
    findFirstAndLast(arr, x); // first : 1, 4
    return 0;
}

