// Breadth First Search_Single Source Shortest Path (SSSP).cpp
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>

#define NL '\n'
using namespace std;
const int SIZE = 1e4;
const int WHITE = 0;
const int GRAY = -1;
const int BLACK = 1;

vector< int > G[SIZE];
queue< int > qi;
int visited[SIZE], parent[SIZE], level[SIZE];

void BFS(int src, int target)
{
	while(!qi.empty())
		qi.pop();

	memset(visited, 0, sizeof(visited));
	memset(parent, 0, sizeof(parent));
	memset(level, 0, sizeof(level));

	qi.push(src);
	visited[src] = GRAY;
	level[src] = 0;

	printf("Graph Traversal through BFS: ");
	printf("%d ", src);

	int u, v, I;
	while (!qi.empty())
	{
		u = qi.front();
		qi.pop();

		for (I = 0; I < G[u].size(); I++)
		{
			v = G[u][I];
			if (visited[v] == WHITE)
			{
				printf("%d ", v);
				level[v] = level[u] + 1;
				parent[v] = u;
				visited[v] = GRAY;
				qi.push(v);
			}
		}
		visited[u] = BLACK;
	}

	printf("\nDistance from source to each node:\n");
	for (I = 1; I <= target; I++)
		printf("%d to %d distance %d\n", src, I, level[I]);

	for(I = 1; I <= target; I++)
		cout << I << " = " << parent[I] << NL;

	/*
	Printing the Shortest Path from source to target node using Parent-child relation
	*/
	printf("Shortest Path from %d to %d: %d ", src, target, target);
	int x = target;
	while (x != src)
	{
		printf("%d ", parent[x]);
		x = parent[x];
	}
}

int main()
{
	int tcases, I, J, K, N, n, m, cnt = 0, len,u ,v, edge, src, target;

	printf("Enter the number of node and edge: ");
	scanf("%d %d", &n, &edge);

	printf("Adjacency List:\n");
	for (I = 0; I < edge; I++)
	{
			scanf("%d%d", &u, &v);
			if (I == 0)
				src = u;
			G[u].push_back(v);
			G[v].push_back(u);
	}
	printf("Enter the source and the target node: ");
	scanf("%d %d", &src, &target);
	BFS(src, target);

	return 0;
}

/*
10 26

1 2
1 3
1 4
2 1
2 6
3 1
3 7
3 8
4 1
4 7
5 8
5 10
6 2
6 10
7 3
7 4
7 8
7 9
8 3
8 5
8 7
9 7
9 10
10 5
10 6
10 9

1 10
*/