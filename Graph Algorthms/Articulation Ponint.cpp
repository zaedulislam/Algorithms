#include <bits/stdc++.h>

using namespace std;

#define NL '\n'
#define SF scanf
#define PF printf
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define PB push_back


const int SIZE = 1e6;
bool articulationPoint[SIZE], visited[SIZE];
int low[SIZE], DT[SIZE], parent[SIZE];
int t = 0, children, root;
vector<int> G[SIZE];


void FindArticulationPoint(int u)
{
	int I, v, SZ;
	t++;
	DT[u] = t;
	low[u] = t;
	visited[u] = true;
	children = 0;

	SZ = G[u].size();
	for (I = 0; I < SZ; I++)
	{
		v = G[u][I];

		if(v == parent[u])
			continue;
		if (visited[v] == true)
			low[u] = min(low[u], DT[v]);
		if(visited[v] == false)
		{
			parent[v] = u;

			FindArticulationPoint(v);

			low[u] = min(low[u], low[v]);

			if(DT[u] <= low[v] && u != root)
				articulationPoint[u] = true;

			children++;
		}

		if((children > 1) && (u == root))
			articulationPoint[u] = true;

	}

	t++;

}



int main()
{

	int T, I, J, K, N, n, m, cnt = 0, len, u, v;

	cin >> n >> m;

	for (I = 0; I < m; I++)
	{
		cin >> u >> v;

		G[u].PB(v);
		G[v].PB(u);
	}

	root = 1;
	FindArticulationPoint(1);

	cout << "Discovery Time:\n";
	for (I = 1; I <= n; I++)
		cout << DT[I] << ' ';

	cout << NL;

	cout << "Articulation Point:\n";
	for(I = 1; I <= n; I++)
	{
		if(articulationPoint[I] == true)
			cout << I << ' ';
	}

	return 0;
}


/*
7 7
1 2
1 3
3 4
3 7
4 6
4 5
6 7

*/

