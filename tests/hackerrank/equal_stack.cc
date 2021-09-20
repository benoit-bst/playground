#include <bits/stdc++.h>

using namespace std;

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {

    // compute height
    int height_1 = accumulate(h1.begin(), h1.end(), 0);
    int height_2 = accumulate(h2.begin(), h2.end(), 0);
    int height_3 = accumulate(h3.begin(), h3.end(), 0);

    // edge case
    if (height_1 == height_2 && height_2 == height_3)
        return height_1;

    bool equal_height = false;
    int r1 = 0, r2 = 0, r3 = 0;
    while(!equal_height) {
        if (height_1 >= height_2 && height_1 >= height_3) {
            height_1 -= h1[r1];
            r1++;
        } else if (height_2 >= height_1 && height_2 >= height_3) {
            height_2 -= h2[r2];
            r2++;
        } else if (height_3 >= height_1 && height_3 >= height_2) {
            height_3 -= h3[r3];
            r3++;
        }
        if ((height_1 == height_2 && height_2 == height_3) || (height_1 == 0 && height_2 == 0 && height_3 == 0)) {
            equal_height = true;
        }
    }
    return height_1;

}


// g++ -std=c++11 equal_stack.cc
int main()
{
    cout << equalStacks({3, 2, 1, 1, 1}, {4, 3, 2}, {1, 1, 4, 1}) << endl;

    return 0;
}
