#include <bits/stdc++.h>
using namespace std;


// Time Complexity: O(N)
// Auxiliary Space: O(N)
vector< pair<int, int> > brute_findSubArrays(int arr[], int n)
{
    vector <pair<int, int>> out;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                out.push_back(make_pair(i, j));
            }
        }
    }

    return out;
}


// Time Complexity: O(N)
// Auxiliary Space: O(N)
vector< pair<int, int> > findSubArrays(int arr[], int n)
{
    // create an empty map
    unordered_map<int, vector<int> > map;

    // create an empty vector of pairs to store
    // subarray starting and ending index
    vector <pair<int, int>> out;

    // Maintains sum of elements so far
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        // add current element to sum
        sum += arr[i];

        // if sum is 0, we found a subarray starting
        // from index 0 and ending at index i
        if (sum == 0)
            out.push_back(make_pair(0, i));

        // If sum already exists in the map there exists
        // at-least one subarray ending at index i with
        // 0 sum
        if (map.find(sum) != map.end())
        {
            // map[sum] stores starting index of all subarrays
            vector<int> vc = map[sum];
            for (auto it = vc.begin(); it != vc.end(); it++)
                out.push_back(make_pair(*it + 1, i));
        }

        // Important - no else
        map[sum].push_back(i);
    }

    // return output vector
    return out;
}

// Utility function to print all subarrays with sum 0
void print(vector<pair<int, int>> out)
{
    for (auto it = out.begin(); it != out.end(); it++)
        cout << "Subarray found from Index " <<
            it->first << " to " << it->second << endl;
}

// Driver code
int main()
{
    int arr[] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<pair<int, int> > out = brute_findSubArrays(arr, n);
    // Subarray found from Index 0 to 10
    // Subarray found from Index 2 to 4
    // Subarray found from Index 2 to 6
    // Subarray found from Index 5 to 6
    // Subarray found from Index 6 to 9

    // if we didn’t find any subarray with 0 sum,
    // then subarray doesn’t exists
    if (out.size() == 0)
        cout << "No subarray exists";
    else
        print(out);
    cout << endl;

    out = findSubArrays(arr, n);
    // Subarray found from Index 2 to 4
    // Subarray found from Index 2 to 6
    // Subarray found from Index 5 to 6
    // Subarray found from Index 6 to 9
    // Subarray found from Index 0 to 10

    // if we didn’t find any subarray with 0 sum,
    // then subarray doesn’t exists
    if (out.size() == 0)
        cout << "No subarray exists";
    else
        print(out);
    return 0;
}
