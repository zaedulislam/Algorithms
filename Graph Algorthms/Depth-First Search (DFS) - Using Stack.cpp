// Depth First Search (DFS) - Using Stack.cpp
#include<iostream>
#include<cstdio>

#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

#define NL '\n'
using namespace std;

const int White = -1;
const int Gray = 0;
const int Black = -2;


vector<int>G[sz];
int visited[sz];
int edge_id[sz];

// src is the starting vertex
// node is the number of vertices
void DFS(int src, int destination)
{
	//int I;
	//for (I = 0; I < node; I++)
		//edge_id[I] = visited[I] = 0;
	printf("Graph Traversal Through DFS: %d ",src);
	visited[1] = 1;

	stack<int>S;
	S.push(src);

	while (!S.empty()){
		int u = S.top();

		S.pop();
		while (edge_id[u] < G[u].size()){
			// Start looking into edges, from  the place we left
			int v = G[u][edge_id[u]];
			edge_id[u]++; // Update the edge pointer to check next time
			// If the vertex is not already visited
			if (visited[v] == 0){
				printf("%d ", v);
				visited[v] = 1;
				// Order of push important for DFS
				S.push(u); // First we will check v,
				// we will come back to u
				// Note, Stack is LIFO. So v will be popped before u.
				S.push(v);
				break;
			}
		}
	}
	cout << NL;
}

int main()
{
	int node, edge, x, y, src,destination;
	char ifalse, c;
	printf("Enter the number of node/vertex and edge: ");
	scanf("%d%d%c", &node, &edge, &ifalse);

	printf("Enter D or U: ");
	scanf("%c", &c);

	if (c == 'U')
		edge = 2 * edge;

	printf("Adjacency List:\n");

	int I;
	for (I = 0; I < edge; I++){
		scanf("%d%d", &x, &y);
		if (I == 0)
			src = x;
		G[x].push_back(y);
	}
	printf("Enter the source and the destination node: ");
	scanf("%d%d", &src, &destination);
	DFS(src, destination);

	return 0;
}
/*
1 2
1 4
1 6
2 1
2 3
2 5
3 2
3 4
4 1
4 3
5 2
5 6
5 7
6 1
6 5
7 5
7 8
8 7
 */
