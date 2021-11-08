#include <bits/stdc++.h>

using namespace std;

int equalizeArray(vector<int> arr) {

    std::map<int, int> freq;

    for (auto& i: arr) {
        freq[i]++;
    }
    for (auto& val: freq) {
        std::cout << "Element " << val.first << " occurs " << val.second << " times" << endl;
    }

    auto max = std::max_element(freq.begin(), freq.end(),
    [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second; });
    return arr.size() - max->second;

}

// g++ -std=c++11 frequency_max.cc
int main()
{
    vector<int> input = {2, 2, 2, 3, 1};
    cout << equalizeArray(input) << endl;
    // 1 occur 1
    // 2 occur 3
    // 3 occur 1

    return 0;
}
