/*

Given two stings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

Example 1:
Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:
Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:
Input: ransomNote = "aa", magazine = "aab"
Output: true

*/
#include <bits/stdc++.h>

using namespace std;

unordered_map<string,int>::iterator it;

// Put every word from the magazine in a hash table, check if every word from the ransom is in the hash table
bool ransom_note(vector<string> magazine, vector<string> ransom) {

	unordered_map<string, int> map;

    for(int i = 0; i < magazine.size(); i++) {
        map[magazine[i]]++;
    }

    for(int i = 0; i < ransom.size(); i++) {
    	it = map.find(ransom[i]);
    	if(it == map.end()) {
    		return false;
    	} else if(it->second == 0) {
			return false;
    	}
    	map[ransom[i]]--;
    }
    return true;
}

int main(){

    vector<string> magazine = {"a", "a", "b", "c", "c", "d", "e", "f"};
    vector<string> ransom = {"a", "a", "b"};
    cout << ransom_note(magazine, ransom) << endl;

    magazine = {"a", "a", "b", "c", "c", "d", "e", "f"};
    ransom = {"a", "c", "h"};
    cout << ransom_note(magazine, ransom) << endl;

    return 0;
}
