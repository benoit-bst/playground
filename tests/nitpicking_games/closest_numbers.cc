#include <bits/stdc++.h>

using namespace std;


void closest_numbers(vector<int>& input) {

    map<int,int> answer;
    for(int i = 0; i < input.size(); i++) {
       answer.insert(pair<int,int>(input[i], 0));
    }

    sort(input.begin(), input.end());

    // Find the smallest difference
    int smallestDifference = INT_MAX;
    for(int i = 0; i < input.size() - 1; i++) {
    	if(input[i + 1] - input[i] < smallestDifference) {
    		smallestDifference = input[i + 1] - input[i];
    	}
    }

    // Iterate over the map and find smallest diff pairs
    for(auto it = answer.begin(); it != answer.end(); it++) {
    	int key = it->first;
    	auto it2 = answer.find(key+smallestDifference);
    	if(it2 != answer.end()) {
    		// Found SD pair, increment both indices
    		it->second++;
    		it2->second++;
    	}
    }

    // Print solution
    for(auto it = answer.begin(); it != answer.end(); it++) {
		for(int i = 0; i < it->second; i++) {
			cout<<it->first<<" ";
		}
	}
    cout << endl;
}

int main() {

	vector<int> in = {5, 4, 3, 2, 1}; // smallest 1 - pair 1 2, 2 3, 3 4, 4 5
    closest_numbers(in); //

	in = {9, 6, 4, 2, 1};
    closest_numbers(in); // smallest 1 - pair 1 2


	return 0;
}
