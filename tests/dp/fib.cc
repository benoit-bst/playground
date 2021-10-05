#include<bits/stdc++.h>
using namespace std;

// O(2^N)
// golden ration O(1.6180^n)
// Extra Space: O(n) if we consider the function call stack size, otherwise O(1).
int rec_fib(int n)
{
    if (n <= 1)
        return n;
    return rec_fib(n-1) + rec_fib(n-2);
}

// O(N)
// O(N + 2) -> O(N)
int dp_fib(int n)
{
    if (n <= 1)
        return n;

    // Declare an array to store
    // Fibonacci numbers.
    // 1 extra to handle
    // case, n = 0
    int f[n + 2];
    int i;

    // 0th and 1st number of the
    // series are 0 and 1
    f[0] = 0;
    f[1] = 1;

    for(i = 2; i <= n; i++)
    {

       //Add the previous 2 numbers
       // in the series and store it
       f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

// O(N)
// O(1)
int dp_op_fib(int n)
{
    int a = 0, b = 1, c, i;
    if( n == 0)
        return a;
    for(i = 2; i <= n; i++)
    {
       c = a + b;
       a = b;
       b = c;
    }
    return b;
}

//
int main ()
{
    int n = 9;
    cout << rec_fib(n) << endl;
    cout << dp_fib(n) << endl;
    cout << dp_op_fib(n) << endl;
    return 0;
}

