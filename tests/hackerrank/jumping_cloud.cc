#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'jumpingOnClouds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY c as parameter.
 */

int jumpingOnClouds(vector<int> c) {

    int n = c.size();
    int jumps = 0, i = 0;
    while(i < n-1) {
        if(c[i+2] == 0) {
            jumps++;
            i += 2;
        }else if(c[i+1] == 0) {
            jumps++;
            i += 1;
        }
    }
    return jumps;
}

// g++ -std=c++11 jumping_cloud.cc
int main()
{
    vector<int> c = {0, 0, 0, 0, 1, 0}; // 3
    cout << jumpingOnClouds(c) << endl;
    c = {0, 0, 0, 0, 0, 0}; // 3
    cout << jumpingOnClouds(c) << endl;
    c = {0, 1, 0, 1, 0, 1, 0, 1, 0, 0}; // 5
    cout << jumpingOnClouds(c) << endl;
    c = {0, 0, 1, 0, 1, 0, 0, 0}; // 4
    cout << jumpingOnClouds(c) << endl;
}
