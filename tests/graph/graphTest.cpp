#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

// g++ -std=c++11 graphTest.cpp

//------------------------------------------------------
// Les graphs peuvent etres directed, undirected, oriented, weighted
// Tree is a connected graph with no cycles
// A forest is a bunch of tree
//------------------------------------------------------

//------------------------------------------------------
// Algo de DIJKSTRA
// find the shortest path algorithm
// Complexity of O(V^2) for naive but can be O(E + VlogV) for adjacency list (array de list représentation)
// On avance branche par branche en rapportant la distance cumulée au vertex
//------------------------------------------------------

//------------------------------------------------------
// topological sorting
// based on DFS O(E + V)
// used for scheduling job, compilo (determine l'ordre des tâches à compiler) 
//------------------------------------------------------

//------------------------------------------------------
// Detect cycle in a directed graph
// If the tree contains a back edge, we can say the graph has a cycle present.
// Based on DFS.
//------------------------------------------------------

//------------------------------------------------------
// Coloring problem
// - Mobile radio frequency assignment 
// - Sudoku
// - Register allocation
// - Installing new software in cloud
//
// Avec le greedy algorithm
// O(V^2 +E) worst case
//------------------------------------------------------

using namespace std;

class Graph
{
  public:
    Graph(int v);
    ~Graph();
    void addEdge(int v, int w);
    void BFS(int s);
    void DFS(int in);

  private:
  	vector<list<int>> adj;
  	int v;
  	void DFSUtil(int v, vector<bool>& visited);

};

Graph::Graph(int v) : v(v)
{
  adj.resize(v);
}

Graph::~Graph()
{

}

void Graph::addEdge(int v, int w)
{
  adj[v].push_back(w);
}

//---------------------------------
// Breadth First Traversal
// Example :
// - peer to peer : Used to find all neighbor nodes
// - Social networking : find people within a given distance k
// - Gps : find all neighboring locations
// 
// Complexity O(V + E)
//---------------------------------
void Graph::BFS(int s)
{
	vector<bool> visited(v);
	fill(visited.begin(), visited.end(), false);

	list<int> queue;

	visited[s] = true;
	queue.push_back(s);

	list<int>::iterator i; 

  while (!queue.empty())
  {
  	s = queue.front();
  	cout << s << " ";
  	queue.pop_front();

  	for (i = adj[s].begin(); i != adj[s].end(); ++i)
  	{
  		if (!visited[*i])
  		{
  			visited[*i] = true;
  			queue.push_back(*i);
  		}
  	}
  }
}

//---------------------------------
// Depth First Traversal
// Examples :
// - Detecting cycle in a directed graph
// Complexity O(V + E)
//---------------------------------
void Graph::DFSUtil(int v, vector<bool>& visited)
{
	visited[v] = true;
	cout << v << " ";

	for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		if (!visited[*i])
			DFSUtil(*i, visited);
	}
}
void Graph::DFS(int in)
{
	vector<bool> visited(v);
	fill(visited.begin(), visited.end(), false);
  
  DFSUtil(in, visited);
}

int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	g.BFS(2);
	cout << "\n";
	g.DFS(2);

	return 0;
}