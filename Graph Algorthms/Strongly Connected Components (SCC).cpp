// Strongly Connected Components (SCC).cpp
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define NL '\n'
const int SIZE = 1e6;

vector< int > G[SIZE], rG[SIZE];
stack< int > topSort;
int visited[SIZE], SCC[SIZE];

void dfs2(int u)
{
	int I, v;
	visited[u] = 1;
	printf("%d ", u);
	for(I = 0; I < rG[u].size(); I++)
	{
		v = rG[u][I];
		if(!visited[v])
			dfs2(v);
	}
}

void dfs1(int u)
{
	int I, v;
	///printf("%d ", u);
	visited[u] = 1;
	for(I = 0; I  < G[u].size(); I++)
	{
		v = G[u][I];
		if(!visited[v])
			dfs1(v);
	}
	topSort.push(u);
}


int main()
{
	int tcases, I, J, K, N, n, m, cnt = 0, len, u, v;
	scanf("%d", &n);

	for(I = 0; I < n; I++)
	{
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		rG[v].push_back(u);
	}

	for(I = 0; I < n; I++)
	{
		if(!visited[I])
			dfs1(I);
	}

	memset(visited, 0, sizeof(visited));

	while(!topSort.empty())
	{
		u = topSort.top();
		if(!visited[u])
		{
			dfs2(u);
			cout << NL;
		}
		topSort.pop();
	}

	return 0;
}

/*
5
1 0
0 2
2 1
0 3
3 4
*/
