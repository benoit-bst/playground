#include <bits/stdc++.h>
using namespace std;

// Time complexity  : O(N^2)
// space complexity : O(1)
int brut_lis(vector<int>& arr) {

    int max_count = 0;
    for (int i = 0; i < arr.size(); i++) {
        int counter = 1;
        int last = arr[i];
        for (int j = i + 1; j < arr.size(); j++) {

            if (last < arr[j]) {
                counter++;
                last = arr[j];
            }
        }
        if (max_count < counter) {
            max_count = counter;
        }
    }

    return max_count;
}

// Time complexity  : O(N*log(N))
// space complexity : O(N)
int longest_increasing_subsequence(vector<int>& arr)
{
    vector<int> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
        if (it == ans.end()) {
            ans.push_back(arr[i]);
        }
        else {
            // swap val inside ans vector.
            // A new lower bound with swapped value can be done
            *it = arr[i];
        }
    }
    return ans.size();
}

int main()
{
    {
        vector<int> arr = {3, 10, 2, 1, 20};
        cout<<"Length of lis is "<< brut_lis(arr) << endl;
        cout<<"Length of lis is "<< longest_increasing_subsequence(arr) << endl;
        arr = {50, 3, 10, 7, 40, 80};
        cout<<"Length of lis is "<< brut_lis(arr) << endl;
        cout<<"Length of lis is "<< longest_increasing_subsequence(arr) << endl;
        arr = {3, 2};
        cout<<"Length of lis is "<< brut_lis(arr) << endl;
        cout<<"Length of lis is "<< longest_increasing_subsequence(arr) << endl;
    }
}
