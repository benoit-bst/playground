#include <bits/stdc++.h>
using namespace std;


// Time complexity of the above naive recursive approach is O(2^n)
// space complexity : O(N) -> O(N) if the function calling matters
int rec_lcs( char *X, char *Y, int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1])
        return 1 + rec_lcs(X, Y, m-1, n-1);
    else
        return max(rec_lcs(X, Y, m, n-1), rec_lcs(X, Y, m-1, n));
}

// Time complexity  : O(N + M)
// space complexity : O(N)
int hash_lcs( char *X, char *Y, int m, int n )
{
    int counter = 0;
    unordered_map<char, int> seen;
    for (int i = 0; i < m; i++) {
        ++seen[X[i]];
    }
    for (int i = 0; i < n; i++) {
        if (seen.find(Y[i]) != seen.end()) {
            counter++;
        }

    }
    return counter;
}

// Time complexity  : O(m*n)
// space complexity : O(m*n)
int dp_lcs( char *X, char *Y, int m, int n )
{
    int L[m+1][n+1];
    int i, j;

    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
        that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
        if (i == 0 || j == 0)
            L[i][j] = 0;

        else if (X[i-1] == Y[j-1])
            L[i][j] = L[i-1][j-1] + 1;

        else
            L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
    return L[m][n];
}

int main()
{
    {
        char X[] = "AGGTAB";
        char Y[] = "GXTXAYB";

        int m = strlen(X);
        int n = strlen(Y);

        cout<<"Length of LCS is "<< rec_lcs( X, Y, m, n ) ;
    }
    {
        char X[] = "AGGTAB";
        char Y[] = "GXTXAYB";

        int m = strlen(X);
        int n = strlen(Y);

        cout<<"Length of LCS is "<< hash_lcs( X, Y, m, n ) ;
    }
    {
        char X[] = "AGGTAB";
        char Y[] = "GXTXAYB";

        int m = strlen(X);
        int n = strlen(Y);

        cout<<"Length of LCS is "<< dp_lcs( X, Y, m, n ) ;
    }
    return 0;
}
