#include <bits/stdc++.h>

using namespace std;

int findMedian(vector<int> arr)
{
    sort(arr.begin(),arr.end());
    int x = (arr.size() + 1)/2 ;
    return arr[x-1];
}

double findMedian_2(vector<int> arr)
{
    sort(arr.begin(),arr.end());
    int n = arr.size();

    // check for even case
    if (n % 2 != 0)
        return (double)arr[n / 2];

    return (double)(arr[(n - 1) / 2] + arr[n / 2]) / 2.0;
}

int main()
{
    vector<int> in = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << findMedian(in) << endl; // 5
    cout << findMedian_2(in) << endl; // 5.5

    in = {1, 2, 3, 4, 5, 6, 7,};
    cout << findMedian(in) << endl; // 4
    cout << findMedian_2(in) << endl; // 4
    return 0;
}
