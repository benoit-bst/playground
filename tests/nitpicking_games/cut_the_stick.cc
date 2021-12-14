#include <bits/stdc++.h>

using namespace std;

// You will iteratively cut the sticks into smaller sticks,
// discarding the shortest pieces until there are none left.
// At each iteration you will determine the length of the shortest stick remaining,
// cut that length from each of the longer sticks and then discard
// all the pieces of that shortest length.
// When all the remaining sticks are the same length,
// they cannot be shortened so discard them.
//
// Given the lengths of n sticks, print the number of sticks
// that are left before each iteration until there are none left.
//
// Example
//
// arr = [1,2,3]
//
// The shortest stick length is 1,
// so cut that length from the longer two and discard the pieces of length 1.
// Now the lengths are arr=[1,2].
// Again, the shortest stick is of length 1,
// so cut that amount from the longer stick and discard those pieces.
// There is only one stick left,arr=[1],
// so discard that stick.
// The number of sticks at each iteration are answer=[3,2,1].
//
// Output :
// for each iteration we return the number of stick remaining

void cut_the_stick(vector<int>& sticks) {
    sort(sticks.begin(), sticks.end());

    int count = 1;
    int tmp = sticks.size();

    // Corner case
	if(sticks.size() == 1) {
		cout<<"1";
	}
	if(sticks.size() <= 0) {
		cout<<"0";
	}
	cout << tmp << endl;

	for(int i = 1; i < sticks.size(); ++i) {

		if(sticks[i] != sticks[i-1]) {

			tmp -= count;

			cout << tmp << endl;
			count = 1;

		} else {
			count++;
		}
    }
}

int main(){

	vector<int> sticks = {2, 1, 3};
    cut_the_stick(sticks); // 3 2 1

	sticks = {2, 1, 3, 5, 10};
    cut_the_stick(sticks); // 5 4 3 2 1

	sticks = {3, 2, 6, 7, 10};
    cut_the_stick(sticks); // 5 4 3 2 1

	return 0;
}
