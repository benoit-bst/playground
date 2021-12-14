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

            // Swapping done
            swap(a[l], a[i]); // BACKTRACK
        }
    }
}

// Example 1: Print all permutations of a string (can be easily modified to print other data)
// Runs in O(p) time, where p is the number of permutations of the string. Note that this
// is much more efficient than a naive algorihtm for strings with duplicate letters.
// "aaaaa" for example, has only one permutation.
void permute2(string s, unordered_map<char,int> count, string perm) {

		for(auto it = count.begin(); it != count.end(); it++) {

			if(it->second > 0) {
				count[it->first]--;
				if(s.size() - perm.size() == 1) {
					// Permutation is complete
					cout<<perm + it->first<<"\n";
				} else {
					permute2(s, count, perm + it->first);
				}
				count[it->first]++; // BACKTRACK
			}
		}
}

void printPermutations(string s) {
	// Count the number of times each letter appears in the string
	unordered_map<char,int> count; // count['a'] -> # of times 'a' appears in s
	for(int i = 0; i < s.size(); i++) {
		count[s[i]]++;
	}
	permute2(s, count, "");
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
        printPermutations(str);
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
        printPermutations(str);
    }

    return 0;
}
