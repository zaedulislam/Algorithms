/*
Bellman-Ford Algorithm (SSSP).cpp
Notes
1) Negative weights are found in various applications of graphs. For example, 
instead of paying cost for a path, we may get some advantage if we follow 
the path.

2) Bellman-Ford works better (better than Dijksra’s) for distributed systems. 
Unlike Dijksra’s where we need to find minimum value of all vertices, in 
Bellman-Ford, edges are considered one by one.

Time complexity: O(N * E)

*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
#define NL '\n'
#define SF scanf
#define PF printf
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define pii pair<int, int>
#define INF (1 << 31) - 1

const int SIZE = 100;
vector<pii> G[SIZE];
int dist[SIZE], parent[SIZE];

void BellmanFord(int src, int V, int E)
{
	int I, J, u, v, costUV, flag;

	// Step 1: Initialize distances from src to all other vertices	
	// as INFINITE
	for(I = 0; I <= V; I++)
		dist[I] = INF;

	dist[src] = 0;
	parent[src] = -1;

	/*
	Bellman Ford routine
	Step 2: Relax all edges |V| - 1 times. A simple shortest path from src to 
	any other vertex can have at-most |V| - 1  edges.
	*/
	for(I = 1; I <= V - 1; I++)	// Relax all E edges V-1 times, overall O(VE)
	{
		for(u = 1; u <= V; u++)		// These two loops = O(E)
		{
			for(J = 0; J < G[u].size(); J++)
			{
				v = G[u][J].first;		// We can record SP spanning here if needed
				costUV = G[u][J].second;

				if(dist[u] + costUV < dist[v])
				{
					dist[v] = dist[u] + costUV;			// Relax
					parent[v] = u;
				}

			}

		}

	}

	/*
	Step 3: check for negative-weight cycles.  The above step  guarantees shortest 
	distances if graph doesn't contain negative weight cycle.  If we get a shorter
	path, then there is a cycle.
	*/
	flag = 0;
    for(u = 1; u <= V; u++)		 // one more pass to check
	{
		for(J = 0; J < G[u].size(); J++)
		{
			v = G[u][J].first;
			costUV = G[u][J].second;

			if(dist[u] + costUV < dist[v])				// should be false
			{
				flag = 1;					// but if true, then negative cycle exists!
				break;
			}

		}

	}

	if(flag == 1)
		PF("Cycle Exists.\n");
	else
	{
		PF("\n");
		for(I = 1; I <= V; I++)
			printf("SSSP(%d, %d) = %d\n", src, I, dist[I]);
	}


}

int main()
{
	int tcases, I, J, K, N, n, m, cnt = 0, len, E, u, v, w;

	SET(parent);

	SF("%d%d", &N, &E);

	for(I = 0; I < E; I++)
	{
		SF("%d%d%d",&u, &v, &w);

		G[u].push_back(pii(v, w));
		G[v].push_back(pii(v, w));
	}

	BellmanFord(1, N, E);

	return 0;
}

/*
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 -1
*/


