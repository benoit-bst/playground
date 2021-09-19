#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'jumpingOnClouds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY c as parameter.
 */

int jumpingOnClouds(vector<int> c) {

    int ans = 0;
    int position = 0;
    int n = c.size();

    while (position < n - 1) {
        position++;
        if (position + 1 <= n - 1 && c[position + 1] != 1) {
        position++;
        }
        ans++;
    }
    return ans;
}

// g++ -std=c++11 jumping_cloud.cc
int main()
{
    vector<int> c = {0, 0, 0, 0, 1, 0};
    cout << jumpingOnClouds(c) << endl;


}
