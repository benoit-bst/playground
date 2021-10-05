#include <bits/stdc++.h>

using namespace std;

bool _is_present_in_dic(vector<string>& dic, string in) {

    for (int i = 0; i < dic.size(); ++i) {
        if (in == dic[i]) {
            return true;
        }
    }
    return false;
}


// O(2^n)
// O(N^2)
void is_present(vector<string>& dic, string in, set<string>& res) {

    if (in.size() == 0) {
        return;
    }

    for (int i = 1; i <= in.size(); ++i) {
        if (_is_present_in_dic(dic, in.substr(0, i))) {
            res.insert(in.substr(0, i));
        }
        is_present(dic, in.substr(i, in.size() - 1), res);
    }
}

int main()
{
    vector<string> dic = {"i", "like", "sam", "samsung", "mobile", "ice"};

    {
        string input = "isam";
        set<string> res;
        is_present(dic, input, res);
        for (auto& _val : res) {
            cout << _val <<  " ";
        } cout << endl;
    }
    {
        string input = "isam";
        set<string> res;
        is_present(dic, input, res);
        for (auto& _val : res) {
            cout << _val <<  " ";
        } cout << endl;
    }
    {
        string input = "samlikei";
        set<string> res;
        is_present(dic, input, res);
        for (auto& _val : res) {
            cout << _val <<  " ";
        } cout << endl;
    }
    {
        string input = "samsunglikei";
        set<string> res;
        is_present(dic, input, res);
        for (auto& _val : res) {
            cout << _val <<  " ";
        } cout << endl;
    }

    return 0;
}

