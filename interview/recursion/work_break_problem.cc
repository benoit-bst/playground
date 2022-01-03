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

// Recursion
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

// DP
// O(n*s) where s is the length of
// the largest string in the dictionary and n is the length of the given string.
bool wordBreak(vector<string>& dic, string str, set<string>& res)
{
    int size = str.size();
    if (size == 0)   return true;

    // Create the DP table to store results of subroblems. The value wb[i]
    // will be true if str[0..i-1] can be segmented into dictionary words,
    // otherwise false.
    vector<bool> wb(size + 1, 0);

    for (int i = 1; i <= size; ++i)
    {
        // if wb[i] is false, then check if current prefix can make it true.
        // Current prefix is "str.substr(0, i)"
        if (wb[i] == false && _is_present_in_dic(dic, str.substr(0, i) ))
            res.insert(str.substr(0, i));
            wb[i] = true;

        // wb[i] is true, then check for all substrings starting from
        // (i+1)th character and store their results.
        if (wb[i] == true)
        {
            // If we reached the last prefix
            if (i == size)
                return true;

            for (int j = i+1; j <= size; j++)
            {
                // Update wb[j] if it is false and can be updated
                // Note the parameter passed to dictionaryContains() is
                // substring starting from index 'i' and length 'j-i'
                if (wb[j] == false && _is_present_in_dic(dic, str.substr(i, j-i) ))
                    res.insert(str.substr(i, j-i));
                    wb[j] = true;

                // If we reached the last character
                if (j == size && wb[j] == true)
                    return true;
            }
        }
    }

    /* Uncomment these lines to print DP table "wb[]"*/
     //for (int i = 1; i <= size; i++)
        //cout << " " << wb[i];

    // If we have tried all prefixes and none of them worked
    return false;
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
        res = {};
        wordBreak(dic, input, res);
        for (auto& _val : res) {
            cout << _val <<  " ";
        } cout << endl;
    }
    {
        string input = "sami";
        set<string> res;
        is_present(dic, input, res);
        for (auto& _val : res) {
            cout << _val <<  " ";
        } cout << endl;
        res = {};
        wordBreak(dic, input, res);
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
        res = {};
        cout << wordBreak(dic, input, res) << endl;
        for (auto& _val : res) {
            cout << _val <<  " ";
        } cout << endl;
    }

    return 0;
}

