#include <bits/stdc++.h>

using namespace std;

bool canJump(vector<int> nums) {

    if (nums.size() < 1) {
        return false;
    }
    int reachable = 0;
    for (int i = 0; i <= reachable && i < nums.size(); ++i) {
        reachable = max(reachable, i + nums[i]);
    }
    return reachable >= nums.size() - 1;
}

// g++ -std=c++11 jump_game.cc
int main()
{
    vector<int> c = {2, 3, 1, 1, 4}; // 3
    cout << canJump(c) << endl;
    c = {3, 2, 1, 0, 4}; // 3
    cout << canJump(c) << endl;


    return 0;
}
