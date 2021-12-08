#include <bits/stdc++.h>

using namespace std;


vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {

    vector<int> position;
    position.resize(player.size());
    std::sort(ranked.begin(), ranked.end());

    for (size_t i = 0; i < player.size(); ++i) {

        // erase duplicate
        ranked.erase(unique(ranked.begin(),ranked.end()),ranked.end());

        for (auto val : ranked)
            cout << val << " ";
        cout << endl;

        auto upper1 = std::upper_bound(ranked.begin(), ranked.end(), player[i]);
        position[i] = ranked.size() - (upper1 - ranked.begin()) + 1;
        cout << position[i]<< endl;
        ranked.insert (upper1, player[i] );
    }
    return position;
}

// g++ -std=c++11 Climbing_the_Leaderboard.cc
int main()
{
    vector<int> ranked = {100, 100, 50, 40, 40, 20, 10};
    vector<int> player = {5, 25, 50, 120};
    auto position = climbingLeaderboard(ranked, player);

    // corresponding Positions for the vector player
    // 6 -> 4 -> 2 -> 1
    return 0;
}

