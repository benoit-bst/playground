#include <bits/stdc++.h>

using namespace std;

// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int minKey(vector<pair<int, bool>>& key)
{
    // Initialize min value
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < key.size(); v++)
        if (key[v].second == false && key[v].first < min) {
            min = key[v].first;
            min_index = v;
        }

    return min_index;
}

// A utility function to print the
// constructed MST stored in parent[]
void printMST(vector<int>& parent, vector<vector<int>>& graph)
{
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < graph.size(); ++i)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
}

// time Complexity of the above program is O(V^2)
// space complexity O(V^2)
//
// can optimize with Kruskal’s Minimum Spanning Tree Algorithm
// Time Complexity: O(ElogE) or O(ElogV).
// Sorting of edges takes O(ELogE) time.
// After sorting, we iterate through all edges and apply the find-union algorithm.
// The find and union operations can take at most O(LogV) time.
// So overall complexity is O(ELogE + ELogV) time.
// The value of E can be at most O(V2), so O(LogV) is O(LogE) the same.
// Therefore, the overall time complexity is O(ElogE) or O(ElogV)
void primMST(vector<vector<int>>& graph)
{
    // Array to store constructed MST
    vector<int> parent(graph.size(), 0);

    // int values used to pick minimum weight edge in cut
    // bool To represent set of vertices included in MST
    vector<pair<int, bool>> key(graph.size(), {INT_MAX, false});

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first vertex.
    key[0].first = 0;
    parent[0] = -1; // First node is always root of MST

    for (auto& _vertice : graph) {
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key);
        cout << "-- min key " << u << endl;

        // Add the picked vertex to the MST Set
        key[u].second = true;

        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        for (int v = 0; v < graph.size(); v++) {

            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && key[v].second == false && graph[u][v] < key[v].first ) {
                parent[v] = u;
                key[v].first = graph[u][v];
            }
        }
    }

    // print the constructed MST
    printMST(parent, graph);
}

// Driver code
int main()
{
    /*

       2    3
    (0)--(1)--(2)
    |    / \   |
   6|  8/   \5 |7
    |  /     \ |
    (3)-------(4)
          9

    */
    vector<vector<int>> graph = { { 0, 2, 0, 6, 0 },
                                  { 2, 0, 3, 8, 5 },
                                  { 0, 3, 0, 0, 7 },
                                  { 6, 8, 0, 0, 9 },
                                  { 0, 5, 7, 9, 0 } };

    // Print the solution
    primMST(graph);

    return 0;
}
