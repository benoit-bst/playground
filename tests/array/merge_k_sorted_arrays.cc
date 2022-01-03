#include <bits/stdc++.h>

using namespace std;

// time:  O((n*k)log(n*k))
// space: O(n*k)
void mergeKArrays(vector<vector<int>>& arr, vector<int>& output)
{
    int c = 0;

    //traverse the matrix
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[i].size(); j++)
            output[c++] = arr[i][j];
    }

    //sort the array
    sort(output.begin(), output.end());
}

typedef pair<int, pair<int, int> > ppi;

// time:  O((n*k)log(k))
// space: O(n*k)
void mergeKArrays_heap(vector<vector<int> >& arr, vector<int>& output)
{

    // Create a min heap with k heap nodes. Every
    // heap node has first element of an array
    priority_queue<ppi, vector<ppi>, greater<ppi> > pq;

    for (int i = 0; i < arr.size(); i++)
        pq.push({ arr[i][0], { i, 0 } });

    // Now one by one get the minimum element
    // from min heap and replace it with next
    // element of its array
    while (pq.empty() == false) {
        ppi curr = pq.top();
        pq.pop();

        // i ==> Array Number
        // j ==> Index in the array number
        int i = curr.second.first;
        int j = curr.second.second;

        output.push_back(curr.first);

        // The next element belongs to same array as
        // current.
        if (j + 1 < arr[i].size())
            pq.push({ arr[i][j + 1], { i, j + 1 } });
    }
}

// Driver code
int main()
{
    {
        vector<vector<int>> arr = {
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9, 10},
            {11, 12, 13}
        };
        vector<int> output(13);

        mergeKArrays(arr, output);

        for (int i = 0; i < output.size(); ++i) {
            cout << output[i] << " ";
        } cout << endl;
    }
    {
        vector<vector<int>> arr = {
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9, 10},
            {11, 12, 13}
        };
        vector<int> output;

        mergeKArrays_heap(arr, output);

        for (int i = 0; i < output.size(); ++i) {
            cout << output[i] << " ";
        } cout << endl;
    }
	return 0;
}
