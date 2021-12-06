#include <bits/stdc++.h>

using namespace std;

struct comp
{
    template<typename T>
    bool operator()(const T &l, const T &r) const
    {
        if (l.second != r.second) {
            return l.second > r.second;
        }

        return l.first > r.first;
    }
};

int equalizeArray(vector<int> arr) {

    std::map<int, int> freq;

    for (auto& i: arr) {
        freq[i]++;
    }
    for (auto& val: freq) {
        std::cout << "Element " << val.first << " occurs " << val.second << " times" << endl;
    }

    // max by idx
    auto max = std::max_element(freq.begin(), freq.end());
    cout << "max val : " << max->first << " - " << max->second << endl;

    // max by value
    max = std::max_element(freq.begin(), freq.end(),
    [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second; });
    cout << "max val : " << max->first << " - " << max->second << endl;

    // create a set
    std::set<std::pair<int, int>, comp> set(freq.begin(), freq.end());
   for (auto const &pair: set) {
        std::cout << '{' << pair.first << "," << pair.second << '}' << std::endl;
   }

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
    // max val : 3 - 1
    // max val : 2 - 3
    // {2,3}
    // {3,1}
    // {1,1}
    // 2

    return 0;
}
