// Recursive C++ program for
// coin change problem.
#include <bits/stdc++.h>
using namespace std;

// Recursive
// O(2*m*n)
// Returns the count of ways we can
// sum S[0...m-1] coins to get sum n
int count(vector<int> S, int m, int total)
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
    return count(S, m - 1, total) +
           count(S, m, total - S[m - 1]);
}

// O(m*n)
int dp_count( vector<int> S, int m, int n )
{
    int i, j, x, y;

    // We need n+1 rows as the table
    // is constructed in bottom up
    // manner using the base case 0
    // value case (n = 0)
    int table[n + 1][m];
    for (int u = 0; u < n + 1; ++u) {
        for (int w = 0; w < m; ++w)
            table[u][w] = 0;
    }

    // Fill the entries for 0
    // value case (n = 0)
    for (i = 0; i < m; i++)
        table[0][i] = 1;

    // Fill rest of the table entries
    // in bottom up manner
    for (i = 1; i < n + 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0;

            // Count of solutions excluding S[j]
            y = (j >= 1) ? table[i][j - 1] : 0;

            // total count
            table[i][j] = x + y;
        }
    }
    return table[n][m - 1];
}

// Driver code
int main()
{
    vector<int> arr = { 1, 2, 3 };
    int m = arr.size();
    cout << " " << count(arr, m, 4) << endl;
    cout << " " << dp_count(arr, m, 4) << endl;

    arr = { 1, 2 };
    m = arr.size();
    cout << " " << count(arr, m, 20) << endl;
    cout << " " << dp_count(arr, m, 20) << endl;

    return 0;
}

// This code is contributed by shivanisinghss2110
