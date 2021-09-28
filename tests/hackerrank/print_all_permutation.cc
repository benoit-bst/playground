#include <bits/stdc++.h>

using namespace std;

// O(n * n!)
void permute(string a, int l, int r, set<string>& res)
{
    // Base case
    if (l == r)
        res.insert(a);
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {
            // Swapping done
            swap(a[l], a[i]);

            // Recursion called
            permute(a, l+1, r, res);
        }
    }
}

int main()
{
    {
        string str = "ABC";
        set<string> res;
        int n = str.size();
        permute(str, 0, n-1, res);
        cout << "set size " << res.size() << endl;
        for (auto& _val : res) {
            cout << _val << " ";
        } cout << endl;
    }
    {
        string str = "ABCD";
        set<string> res;
        int n = str.size();
        permute(str, 0, n-1, res);
        cout << "set size " << res.size() << endl;
        for (auto& _val : res) {
            cout << _val << " ";
        } cout << endl;
    }

    return 0;
}
