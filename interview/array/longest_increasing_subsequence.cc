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

int dp_lis(vector<int> arr)
{
    int n = arr.size();
    vector<int> b;
    set<int> s;

    // setting iterator for set
    set<int>::iterator it;

    // storing unique elements
    for (int i = 0; i < n; i++) {
        s.insert(arr[i]);
    }

    // creating sorted vector
    for (it = s.begin(); it != s.end(); it++) {
        b.push_back(*it);
    }
    int m = b.size(), i, j;
    int dp[m + 1][n + 1];

    // storing -1 in dp multidimentional array
    for (i = 0; i < m + 1; i++) {
        for (j = 0; j < n + 1; j++) {
            dp[i][j] = -1;
        }
    }
    // Finding Longest common Subsequence of the two
    // arrays
    for (i = 0; i < m + 1; i++) {
        for (j = 0; j < n + 1; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (arr[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main()
{
    {
        vector<int> arr = {3, 10, 2, 1, 20};
        cout<<"Length of lis is "<< brut_lis(arr) << endl;
        cout<<"Length of lis is "<< dp_lis(arr) << endl;
        cout<<"Length of lis is "<< longest_increasing_subsequence(arr) << endl;
        arr = {50, 3, 10, 7, 40, 80};
        cout<<"Length of lis is "<< brut_lis(arr) << endl;
        cout<<"Length of lis is "<< dp_lis(arr) << endl;
        cout<<"Length of lis is "<< longest_increasing_subsequence(arr) << endl;
        arr = {3, 2};
        cout<<"Length of lis is "<< brut_lis(arr) << endl;
        cout<<"Length of lis is "<< dp_lis(arr) << endl;
        cout<<"Length of lis is "<< longest_increasing_subsequence(arr) << endl;
    }
}
