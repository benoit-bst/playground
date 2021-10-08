#include <bits/stdc++.h>
using namespace std;

// A utility function to get
// maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to get minimum
// number of trials needed in worst
// case with n eggs and k floors
// time is exponential
// space 0(1)
int eggDrop(int n, int k)
{
    // If there are no floors,
    // then no trials needed.
    // OR if there is one floor,
    // one trial needed.
    if (k == 1 || k == 0)
        return k;

    // We need k trials for one
    // egg and k floors
    if (n == 1)
        return k;

    int min = INT_MAX, x, res;

    // Consider all droppings from
    // 1st floor to kth floor and
    // return the minimum of these
    // values plus 1.
    for (x = 1; x <= k; x++) {
        res = max(
            eggDrop(n - 1, x - 1),
            eggDrop(n, k - x));
        if (res < min)
            min = res;
    }

    return min + 1;
}

// Time Complexity: O(n*k^2).
//Where ‘n’ is the number of eggs and ‘k’ is the number of floors, as we use a nested for loop ‘k^2’ times for each egg
// Auxiliary Space: O(n*k)
int dp_eggDrop(int n, int k)
{
    /* A 2D table where entry
    eggFloor[i][j] will represent
    minimum number of trials needed for
    i eggs and j floors. */
    vector<vector<int>> eggFloor(n + 1, std::vector<int>(k + 1, 0));
    int res;
    int i, j, x;

    // We need one trial for one floor and 0
    // trials for 0 floors
    for (i = 1; i <= n; i++) {
        eggFloor[i][1] = 1;
        eggFloor[i][0] = 0;
    }

    // We always need j trials for one egg
    // and j floors.
    for (j = 1; j <= k; j++)
        eggFloor[1][j] = j;

    cout << "----------------"<< endl;
    for (int z = 0; z < n + 1; z++) {
        cout << "-"<< endl;
        for (int y = 0; y < k + 1; y++) {
            cout << eggFloor[z][y] << " ";
        }
        cout << endl;
    }
    cout << "----------------"<< endl;

    // Fill rest of the entries in table using
    // optimal substructure property
    for (i = 2; i < n + 1; ++i) {
        for (j = 2; j < k + 1; ++j) {
            eggFloor[i][j] = INT_MAX;
            for (x = 1; x <= j; ++x) {
                res = 1 + max(
                            eggFloor[i - 1][x - 1],
                            eggFloor[i][j - x]);
                if (res < eggFloor[i][j])
                    eggFloor[i][j] = res;
            }
        }
    }
    cout << "----------------"<< endl;
    for (int z = 0; z < n + 1; z++) {
        cout << "-"<< endl;
        for (int y = 0; y < k + 1; y++) {
            cout << eggFloor[z][y] << " ";
        }
        cout << endl;
    }
    cout << "----------------"<< endl;

    // eggFloor[n][k] holds the result
    return eggFloor[n][k];
}

// Driver program to test
// to pront printDups
int main()
{
    int n = 4, k = 20;
    cout << "Minimum number of trials "
            "in worst case with "
         << n << " eggs and " << k
         << " floors is "
         << eggDrop(n, k) << endl;
    cout << "Minimum number of trials "
            "in worst case with "
         << n << " eggs and " << k
         << " floors is "
         << dp_eggDrop(n, k) << endl;
    return 0;
}
