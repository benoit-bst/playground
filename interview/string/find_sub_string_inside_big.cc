#include <bits/stdc++.h>

using namespace std;

// time: O(NB_Smalls*N)
// O(NB_smalls)
unordered_map<string, int> find_substring_inside_big(string str, vector<string>& smalls)
{
    unordered_map<string, int> hash_positions;
    for (auto _val : smalls) {
        auto pos = str.find(_val);
        if (pos !=  std::string::npos) {
            hash_positions[_val] = pos;
        }
    }
    return hash_positions;
}

int search(const string& pattern, const string& txt);

// time: O(NB_Smalls*N*M)
// O(NB_smalls)
unordered_map<string, int> find_substring_inside_big_2(string str, vector<string>& smalls)
{
    unordered_map<string, int> hash_positions;
    for (auto _val : smalls) {
        auto pos = search(_val, str);
        if (pos !=  -1) {
            hash_positions[_val] = pos;
        }
    }
    return hash_positions;
}

// O(m*(n-m+1)) -> O(N*M)
// O(1)
int search(const string& pattern, const string& txt)
{
    int M = pattern.size();
    int N = txt.size();

    for (int i = 0; i <= N - M; i++) {
        int j = 0;

        // pattern matching
        for (j = 0; j < M; j++)
            if (txt[i + j] != pattern[j])
                break;

        if (j == M)
            return i;
    }
    return -1;
}

int main() {

    string str = "Icanfrommissipi";
    vector<string> smalls = {"can", "omm", "ipi"};
    auto hash_positions = find_substring_inside_big(str, smalls);
    for (const auto& val : hash_positions) {
        cout << val.first << " - " << val.second << endl;
    } // ipi - 12 , omn - 6 , can - 1
    hash_positions = find_substring_inside_big_2(str, smalls);
    for (const auto& val : hash_positions) {
        cout << val.first << " - " << val.second << endl;
    } // ipi - 12 , omn - 6 , can - 1

    return 0;
}
