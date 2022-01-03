#include <bits/stdc++.h>

using namespace std;

// time O(N*logN + N) -> O(N*logN)
// O(1)
bool are_rotation(string& str1, string& str2)
{
    if (str1.length() != str2.length()) {
        return false;
    }
    string temp = str1 + str2;
    return (temp.find(str2) != string::npos);
}

bool check_rotation(string s, string goal)
{
    if (s.size() != goal.size())
        ;
    queue<char> q1;
    for (int i = 0; i < s.size(); i++) {
        q1.push(s[i]);
    }
    queue<char> q2;
    for (int i = 0; i < goal.size(); i++) {
        q2.push(goal[i]);
    }
    int k = goal.size();
    while (k--) {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if (q2 == q1)
            return true;
    }
    return false;
}

int main() {

    string str1 = "AACD", str2 = "ACDA";
    cout << "are rotation " << are_rotation(str1, str2) << endl; // true
    cout << "are rotation " << check_rotation(str1, str2) << endl; // true


    return 0;
}
