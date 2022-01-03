#include <bits/stdc++.h>

using namespace std;

int findMedian(vector<int> arr)
{
    sort(arr.begin(),arr.end());
    int x = (arr.size() + 1)/2 ;
    return arr[x-1];
}

int main()
{
    vector<int> in = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << findMedian(in) << endl; // 5

    in = {1, 2, 3, 4, 5, 6, 7,};
    cout << findMedian(in) << endl; // 4
    return 0;
}
