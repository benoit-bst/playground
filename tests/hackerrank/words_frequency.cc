#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> count_words(vector<string> words) {


    unordered_map<string, int> hash;
    // for each word
    for (auto& word: words) {
        auto it = hash.find(word);
        if (it != hash.end()) {
            it->second++;
        } else {
            hash[word] = 1;
        }
    }
    return hash;
}

// g++ -std=c++11 frequency_max.cc
int main()
{
    vector<string> input = {"aa", "bb", "aa", "dd", "dd", "ff"};
    auto result = count_words(input);
    for (auto val : result) {
        cout << "key " << val.first << " - " << val.second << endl;
    }

    return 0;
}
