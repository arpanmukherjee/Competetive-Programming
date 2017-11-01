// A C++ Program to check whether a graph is tree or not
#include<iostream>
#include <list>
#include <limits.h>
using namespace std;

// Class for an undirected graph
class Graph
{
	int V; // No. of vertices
	list<int> *adj; // Pointer to an array containing adjacency lists
	bool isCyclicUtil(int v, bool visited[], int parent);
public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // to add an edge to graph
	bool isTree(); // returns true if graph is tree
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
	adj[w].push_back(v); // Add v to w’s list.
}

// A recursive function that uses visited[] and parent to detect
// cycle in subgraph reachable from vertex v.
bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
	// Mark the current node as visited
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		// If an adjacent is not visited, then recur for that adjacent
		if (!visited[*i])
		{
		if (isCyclicUtil(*i, visited, v))
			return true;
		}

		// If an adjacent is visited and not parent of current vertex,
		// then there is a cycle.
		else if (*i != parent)
		return true;
	}
	return false;
}

// Returns true if the graph is a tree, else false.
bool Graph::isTree()
{
	// Mark all the vertices as not visited and not part of recursion
	// stack
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// The call to isCyclicUtil serves multiple purposes
	// It returns true if graph reachable from vertex 0 is cyclcic.
	// It also marks all vertices reachable from 0.
	if (isCyclicUtil(0, visited, -1))
			return false;

	// If we find a vertex which is not reachable from 0 (not marked
	// by isCyclicUtil(), then we return false
	for (int u = 0; u < V; u++)
		if (!visited[u])
		return false;

	return true;
}

// Driver program to test above functions
int main()
{
	int n,m,i,u,v;
	cin>>n>>m;
	Graph g1(n);
	
	for(i=0;i<m;i++)
	{
		cin>>u>>v;
		g1.addEdge(u-1,v-1);
	}
	g1.isTree()?cout<<"YES":cout<<"NO";
	return 0;
}
