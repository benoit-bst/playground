#include <bits/stdc++.h>

using namespace std;

// time : O(N)
// space : O(1)
int inplace_remove_duplicates(vector<int>& arr)
{
    int n = arr.size();
    if (n == 0 || n == 1)
        return n;

    // To store index of next unique element
    int j = 0;

    // Doing same as done in Method 1
    // Just maintaining another updated index i.e. j
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            arr[j++] = arr[i];
        }
    }

    arr[j++] = arr[n-1];

    return j;
}

// time : O(N + N*log(N)) -> O(N*log(N))
// space : O(U) with U = the number of unique number
vector<int> remove_duplicates(vector<int>& arr)
{
    int n = arr.size();
	if (n == 0 || n == 1)
		return arr;

    sort(arr.begin(), arr.end());
    vector<int> temp;

    temp.push_back(arr[0]);
	for (int i = 1; i < n; i++)
    {
		if (arr[i] != arr[i - 1]) {
			temp.push_back(arr[i]);
        }
    }
    return temp;
}

int main()
{
    {
        vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5, 5};

        int n = inplace_remove_duplicates(arr);

        for (int i=0; i<n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    {
        vector<int> arr = {2, 1, 2, 3, 4, 5, 4, 5, 4};
        auto res = remove_duplicates(arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
	return 0;
}
