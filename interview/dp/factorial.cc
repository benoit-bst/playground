#include<bits/stdc++.h>

using namespace std;

// O(N)
int rec_fac(int n)
{
    if (n == 0)
        return 1;
    return n * rec_fac(n-1);
}

// O(N)
// O(N)
int dp_fac(int n)
{
    if (n == 0)
        return 1;

    int f[n];
    int i;

    f[0] = 1;

    for(i = 1; i <= n; i++)
    {
       f[i] = i * f[i - 1];
    }
    return f[n];
}

int main ()
{
    int n = 9;
    cout << rec_fac(n) << endl;
    cout << dp_fac(n) << endl;
    return 0;
}

