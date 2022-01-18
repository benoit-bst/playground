
#include <bits/stdc++.h>
using namespace std;

// Input:  arr[]  = {9:00,  9:40, 9:50,  11:00, 15:00, 18:00}
//         dep[]  = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}
// Output: 3
// There are at-most three trains at a time
// (time between 11:00 to 11:20)

// time  : O(N^2)
// space : O(1)
int brute_findPlatform(int arr[], int dep[], int n)
{

    // plat_needed indicates number of platforms
    // needed at a time
    int plat_needed = 1, result = 1;
    int i = 1, j = 0;

    // run a nested  loop to find overlap
    for (int i = 0; i < n; i++) {
        // minimum platform
        plat_needed = 1;

        for (int j = i + 1; j < n; j++) {
            // check for overlap
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
           (arr[j] >= arr[i] && arr[j] <= dep[i]))
                plat_needed++;
        }

        // update result
        result = max(result, plat_needed);
    }

    return result;
}

// time  : O(N* LogN)
// space : O((N)
int findPlatform(int arr[], int dep[], int n)
{
    // Insert all the times (arr. and dep.)
    // in the multiset.
    multiset<pair<int, char> > order;
    for (int i = 0; i < n; i++) {

        // If its arrival then second value
        // of pair is 'a' else 'd'
        order.insert(make_pair(arr[i], 'a'));
        order.insert(make_pair(dep[i], 'd'));
    }

    int result = 0;
    int plat_needed = 0;

    // Start iterating the multiset.
    for (auto it : order) {

        // If its 'a' then add 1 to plat_needed
        // else minus 1 from plat_needed.
        if (it.second == 'a')
            plat_needed++;
        else
            plat_needed--;

        if (plat_needed > result)
            result = plat_needed;
    }
    return result;
}

// time  : O(N)
// space : O(2360) -> O(1)
int minPlatform(int arrival[], int departure[], int n)
{

    // as time range from 0 to 2359 in 24 hour clock,
    // we declare an array for values from 0 to 2360
    int platform[2361] = {0};
    int requiredPlatform = 1;
    for (int i = 0; i < n; i++) {

        // increment the platforms for arrival
        ++platform[arrival[i]];

         // once train departs we decrease the platform count
        --platform[departure[i] + 1];
    }

    // We are running loop till 2361 because maximum time value
    // in a day can be 23:60
    for (int i = 1; i < 2361; i++) {

        // taking cumulative sum of platform give us required
        // number of platform fro every minute
        platform[i] = platform[i] + platform[i - 1];
        requiredPlatform = max(requiredPlatform, platform[i]);
    }
    return requiredPlatform;
}

// Driver code
int main()
{
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };

    {
        int n = sizeof(arr) / sizeof(arr[0]);
        cout << "Minimum Number of Platforms Required = "
             << brute_findPlatform(arr, dep, n); // Minimum Number of Platforms Required = 3
    }
    {
        int n = sizeof(arr) / sizeof(arr[0]);
        cout << "Minimum Number of Platforms Required = "
             << findPlatform(arr, dep, n); // Minimum Number of Platforms Required = 3
    }
    {
        int n = sizeof(arr) / sizeof(arr[0]);
        cout << "Minimum Number of Platforms Required = "
             << minPlatform(arr, dep, n); // Minimum Number of Platforms Required = 3
    }

    return 0;
}
