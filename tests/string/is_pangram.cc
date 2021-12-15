#include <bits/stdc++.h>

using namespace std;

const int NO_OF_CHARS = 26;
// time O(N*logN + N) -> O(N*logN)
// O(1)
bool is_pangram(string str)
{
    char c = 'a';
    for(int i = 0; i < NO_OF_CHARS; i++) {
        bool found = false;
        for(int j = 0; j < str.length(); j++) {
            if(tolower(str[j]) == c) {
                found = true;
                break;
            }
        }
        if(!found) {
            return false;
        } else if(found && i==25) {
            return true;
        }
        c++;
    }
    return true;
}


int main() {

    string str = "test";
    cout << "Is pangram " << is_pangram(str) << endl; // no

    str = "The quick brown fox jumps over the lazy dog"; // yes
    cout << "Is pangram " << is_pangram(str) << endl;

    str = "The quick brown fox jumps over the lazy do"; // no
    cout << "Is pangram " << is_pangram(str) << endl;

    return 0;
}
