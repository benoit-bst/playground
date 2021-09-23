#include <bits/stdc++.h>

using namespace std;

class LFUCache {

public:

    LFUCache(const int cap);
    void refer(const int input);
    void display();

private:

    vector<pair<int, int> > _values;
    //hashtable for storing the reference address (usefull for the position)
	unordered_map<int, int> ref;
    // the capacity
	int n;
};

LFUCache::LFUCache(const int cap){
    _values.resize(cap);
    //for (auto val : _values) {
    for (size_t i = 0; i < _values.size(); ++i) {
        _values[i].first = -1;
        _values[i].second = -1;
    }
	n=cap;
}

void LFUCache::refer(const int input) {

    if (ref.find(input) == ref.end()) {

        //if the cache size is equal to the capacity
        if(ref.size()==n){
            int low_frequency = INT_MAX;
            int value = 0;
            for(auto val : _values) {
                if (val.second < low_frequency) {
                    low_frequency = val.second;
                    value = val.first;
                }
            }
            _values[(ref.find(value)->second)].first = -1;
            _values[(ref.find(value)->second)].second = -1;
            ref.erase(value);
        }
        for (size_t i = 0; i < _values.size(); ++i) {
            if (_values[i].second == -1) {
                _values[i].first = input;
                _values[i].second = 1;
                ref[input] = i;
                break;
            }
        }
    }
    // Increment frequency
    else {
        int pos = ref.find(input)->second;
        ++_values[pos].second;
    }
};

void LFUCache::display() {
    for (auto val : _values)
	    cout << val.first << " - " << val.second << "; ";
	cout << endl;
};

// Least Recently Used
//
// Driver Code
int main()
{
    size_t cache_size = 4;
    LFUCache ca(cache_size);

    ca.refer(1);
    ca.display();
    ca.refer(2);
    ca.display();
    ca.refer(3);
    ca.display();
    ca.refer(4);
    ca.display();
    ca.refer(2);
    ca.display();
    ca.refer(2);
    ca.display();
    ca.refer(5);
    ca.display();
    ca.refer(6);
    ca.display();

    return 0;
}
