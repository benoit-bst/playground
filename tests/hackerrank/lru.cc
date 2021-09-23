#include <bits/stdc++.h>

using namespace std;

class LRUCache {

public:

    LRUCache(const int cap);
    void refer(const int input);
    void display();

private:

    // store keys of cache
    //Doubly linked list to store the elements
    deque<int> dq;
    //hashtable for storing the reference address (usefull for the position)
	unordered_map<int, deque<int>::iterator> ref;
    // the capacity
	int n;
};


LRUCache::LRUCache(const int cap){
	n=cap;
}

void LRUCache::refer(const int input) {

    if (ref.find(input) == ref.end()) {
        if(ref.size()==n){//if the cache size is equal to the capacity
			int x=dq.back();
			dq.pop_back();//removing the last element from the queue
            ref.erase(x); //erasing the key value pair from the hash table
		}
    } else {
        //el.erase(ref.find(input)->second);
        dq.erase(ref.find(input)->second);
    }
    dq.push_front(input);
    ref[input] = dq.begin();
};

void LRUCache::display() {
    for(auto it=dq.begin(); it!=dq.end(); it++)
	    cout<< *it << " ";
	cout << endl;
};

// Least Recently Used
//
// Driver Code
int main()
{
    size_t cache_size = 4;
    LRUCache ca(cache_size);

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
    ca.refer(5);
    ca.display();

    return 0;
}
