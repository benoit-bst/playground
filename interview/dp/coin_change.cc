// Recursive C++ program for
// coin change problem.
#include <bits/stdc++.h>
using namespace std;

// Recursive
// exponential time !!!!!
int rec_count(vector<int> S, int m, int total)
{

    // If n is 0 then there is 1 solution
    // (do not include any coin)
    if (total == 0)
        return 1;

    // If n is less than 0 then no
    // solution exists
    if (total < 0)
        return 0;

    // If there are no coins and total
    // is greater than 0, then no
    // solution exist
    if (m <= 0 && total >= 1)
        return 0;

    // count is sum of solutions (i)
    // including S[m-1] (ii) excluding S[m-1]
    return rec_count(S, m - 1, total) +
           rec_count(S, m, total - S[m - 1]);
}

int count(vector<int> const &S, int n, int target)
{
    // if the total is 0, return 1 (solution found)
    if (target == 0) {
        return 1;
    }

    // return 0 (solution does not exist) if total becomes negative,
    // no elements are left
    if (target < 0 || n < 0) {
        return 0;
    }

    // Case 1. Include current coin `S[n]` in solution and recur
    // with remaining change `target-S[n]` with the same number of coins
    int include = count(S, n, target - S[n]);

    // Case 2. Exclude current coin `S[n]` from solution and recur
    // for remaining coins `n-1`
    int exclude = count(S, n - 1, target);

    // return total ways by including or excluding current coin
    return include + exclude;
}

// O(m*n)
int dp_count( vector<int> S, int m, int n )
{
     // table[i] will be storing the number of solutions for
     // value i. We need n+1 rows as the table is constructed
     // in bottom up manner using the base case (n = 0)
     int table[n+1];
     // Initialize all table values as 0
     memset(table, 0, sizeof(table));
     // Base case (If given value is 0)
     table[0] = 1;
     // Pick all coins one by one and update the table[] values
     // after the index greater than or equal to the value of the
     // picked coin
     for(int i = 0; i < m; i++){
        for(int j = S[i]; j <= n; j++) {
            table[j] += table[j-S[i]];
        }
     }
     return table[n];
}


int main()
{
    vector<int> arr = { 1, 2, 3 };
    int m = arr.size();
    cout << " " << rec_count(arr, m, 4) << endl;
    cout << " " << count(arr, m - 1, 4) << endl;
    cout << " " << dp_count(arr, m, 4) << endl;

    arr = { 1, 2 };
    m = arr.size();
    cout << " " << rec_count(arr, m, 20) << endl;
    cout << " " << dp_count(arr, m, 20) << endl;

    return 0;
}

