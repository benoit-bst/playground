#include <bits/stdc++.h>

using namespace std;

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {

    int count_apple = 0;
    for (int i = 0; i < apples.size(); ++i) {
        if ((apples[i] + a >= s) && (apples[i] + a <= t)) {
            count_apple++;
        }
    }
    cout << count_apple << endl;
    int count_orange = 0;
    for (int i = 0; i < oranges.size(); ++i) {
        if ((oranges[i] + b >= s) && (oranges[i] + b <= t)) {
            count_orange++;
        }
    }
    cout << count_orange << endl;

}

// g++ -std=c++11 frequency_and_max.cc
int main()
{
    countApplesAndOranges(7, 11, 5, 15 , {-2, 2, 1}, {5, -6});

    return 0;
}
