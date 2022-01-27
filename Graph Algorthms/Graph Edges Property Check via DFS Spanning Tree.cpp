// Depth First Search (DFS) & Topological Sort.cpp
/*
Depth First Search:
Depth First Search is one of the main graph algorithms.
The algorithm works in O(V + E) time where V is the number of vertices and E is the number of edges.

Applications of Depth First Search:

(1) Find any path in the graph from source vertex (u) to all vertices.

(2) Find lexicographically first path in the graph from source (u) to all vertices.

(3) Check if a vertex in a tree is an ancestor of some other vertex.
At the beginning and end of each search call, remember the entry and exit "time" of each vertex. Now, you can
find the answer for any pair of vertices (i,j) in O(1): vertex i is an ancestor of vertex j if and only if
entry[i] < entry[j]  and exit[i] > exit[j].

(4) Find the lowest common ancestor (LCA) of two vertices.

(5) Topological sorting.
Run a series of depth first searches so as to visit each vertex exactly once in O(V + E) time. The required
topological ordering will be the vertices sorted in descending order of exit time.

(6) Check whether a given graph is acyclic and find cycles in a graph.

(7) Find strongly connected components in a directed graph.
First do a topological sorting of the graph. Then transpose the graph and run another series of depth first searches
in the order defined by the topological sort. For each DFS call the component created by it is a strongly connected
component.

(8) Find bridges in an undirected graph.
First convert the given graph into a directed graph by running a series of depth first searches and making each edge
directed as we go through it, in the direction we went. Second, find the strongly connected components in this
directed graph. Bridges are the edges whose ends belong to different strongly connected components.


*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int SIZE = 1000;

vector<int> G[SIZE];
int visited[SIZE];

void DFS(int u)
{
	int I, v;
	visited[u] = 1;
	printf("%d ", u);

	for (I = 0; I < G[u].size(); I++)
	{
		v = G[u][I];
		if (!visited[v])
			DFS(v);
	}
}

int main()
{
	int tcases, caseno = 1, n, I, J, K, N, cnt = 0,
	len, u, v, src, E;

	scanf("%d%d", &N, &E);

	for (I = 0; I < E; I++)
	{
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
	}

	printf("Graph Traversal Through DFS: ");
	for (I = 1; I <= N; I++)
	{
		if (visited[I] == 0)
			DFS(I);
	}
	printf("\n");

	return 0;
}

/*
4 4
2 1
2 3
3 4
1 4

Graph Traversal Through DFS:
1 4 2 3
*/
