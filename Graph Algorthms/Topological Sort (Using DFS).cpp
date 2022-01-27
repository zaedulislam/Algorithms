/*
Topological Sort (Using DFS).cpp

Complexity: Complexity as of DFS O(V + E) where V = Number of nodes and E = Number of edges in the graph.
And Each node andeach edge is visited only once.
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int SIZE = 1000;

vector<int> G[SIZE], topOrder;
int visited[SIZE], D[SIZE], F[SIZE], T = 0;




void DFS(int u)
{
	visited[u] = 1;
	printf("%d ", u);

    int I, v;
	// Starting/Discovery Time.
	D[u] = ++T;
	for (I = 0; I < G[u].size(); I++)
	{
		v = G[u][I];
		if (!visited[v])
			DFS(v);
	}
	// Finishing Time.
	F[u] = ++T;

	// Stores the Topological Order of the Tasks.
	topOrder.push_back(u);
}



int main()
{
	int tcases, caseno = 1, n, I, J, K, N, cnt = 0, len, u, v, src, E;

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
	printf("Topological Order: ");
	for (I = topOrder.size() - 1; I >= 0; I--)
		printf("%d ", topOrder[I]);

	printf("\n");

	return 0;
}

/*
4 4
2 1
2 3
3 4
1 4

Graph Traversal Through DFS: 1 4 2 3
Toplogical Order: 2 3 1 4
*/
