// C++ program for activity selection problem.
// The following implementation assumes that the activities
// are already sorted according to their finish time
#include <bits/stdc++.h>
using namespace std;

// Prints a maximum set of activities that can be done by a single
// person, one at a time.
//  n   -->  Total number of activities
//  s[] -->  An array that contains start time of all activities
//  f[] -->  An array that contains finish time of all activities
//  time O(N)
//  space O(1)
void printMaxActivities(vector<int> s, vector<int> f)
{
    int i, j;

    cout <<"Following activities are selected "<< endl;

    // The first activity always gets selected
    i = 0;
    cout << " " << i;

    // Consider rest of the activities
    for (j = 1; j < s.size(); j++)
    {
      // If this activity has start time greater than or
      // equal to the finish time of previously selected
      // activity, then select it
      if (s[j] >= f[i])
      {
          cout << " " << j;
          i = j;
      }
    }
}

//  time O(N)
//  space O(N)
void SelectActivities(vector<int>s,vector<int>f){
// Vector to store results.
    vector<pair<int,int>>ans;

// Minimum Priority Queue to sort activities in ascending order of finishing time (f[i]).

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;

    for(int i=0;i<s.size();i++){
        // Pushing elements in priority queue where the key is f[i]
        p.push(make_pair(f[i],s[i]));
    }

    auto it = p.top();
    int start = it.second;
    int end = it.first;
    p.pop();
    ans.push_back(make_pair(start,end));

    while(!p.empty()){
        auto itr = p.top();
        p.pop();
        if(itr.second >= end){
            start = itr.second;
            end = itr.first;
            ans.push_back(make_pair(start,end));
        }
    }
    cout << "Following Activities should be selected. " << endl << endl;

    for(auto itr=ans.begin();itr!=ans.end();itr++){
        cout << "Activity started at: " << (*itr).first << " and ends at  " << (*itr).second << endl;
    }
}

// driver program to test above function
int main()
{
    vector<int> s =  {1, 3, 0, 5, 8, 5};
    vector<int> f =  {2, 4, 6, 7, 9, 9};
    printMaxActivities(s, f); // 0 1 3 4
    s =  {5, 1, 3, 0, 8, 5};
    f =  {7, 2, 4, 6, 9, 9};
    SelectActivities(s, f); // 0 1 3 4
    return 0;
}
//this code contributed by shivanisinghss2110
