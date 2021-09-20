#include <bits/stdc++.h>

using namespace std;


// Brute force approach passes all test cases, but as with most questions of this format
// we can do better using a hashtable to get O(n) instead of O(n^2)
int minimumDistances(vector<int> a) {
    int minDistance = INT_MAX;
    for(int i = 0; i < a.size(); i++) {
        for(int j = i+1; j < a.size(); j++) {
            if(a[i] == a[j] && j-i < minDistance) {
                minDistance = j-i;
            }
        }
    }
    if(minDistance == INT_MAX) {
        return -1;
    } else {
        return minDistance;
    }

}

typedef pair<bool, int> LastPositionFound;

int minimumDistances_2(vector<int> nums) {

    unordered_map<int, LastPositionFound> table; // maps value found in array to the last position that value was seen at.
    int best_distance = -1;

    for (size_t index = 0; index < nums.size(); index++)
    {
        int value = nums[index];
        LastPositionFound& lpf = table[value];  // returns {false,0} if not found
        if (lpf.first)
        {
            int distance = index - lpf.second;
            if ((distance < best_distance) || (best_distance == -1))
            {
                best_distance = distance;
            }
        }

        // update reference to hash table entry
        lpf.first = true;
        lpf.second = index;
    }
    return best_distance;
}

// g++ -std=c++11 minimum_distance.cc
int main()
{
    vector<int> input = {7, 1, 3, 4, 1, 7};
    cout << minimumDistances(input) << endl;
    cout << minimumDistances_2(input) << endl;

}
