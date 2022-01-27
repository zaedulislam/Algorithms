
#include <iostream>
#include <cstdio>

#include <string>
#include <cstring>
#include <sstream>

#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>

#include <algorithm>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>

#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

int caseno = 1;
#define NL '\n'
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
#define SF scanf
#define PF printf
#define PC() printf("Case %d: ", caseno++)
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

#define INF 10000000000000000
#define MOD 1000000007
#define pLL pair< LL , LL >
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e5 + 10;

vector< pLL > G[SIZE];
priority_queue< pLL, vector< pLL >, greater < pLL > > pq;
LL dis[SIZE], parent[SIZE], path[SIZE];

void Dijkstra(LL src)
{
	memset(parent, -1, sizeof(parent));

	pq.push(pLL(0, src));
	dis[src] = 0;
	parent[src] = 1;

	pLL tmp;
	LL I, u, v, costUV;
	while (!pq.empty())
	{
		tmp = pq.top();
		u = tmp.second;
		pq.pop();

		for (I = 0; I < G[u].size(); I++)
		{
			v = G[u][I].first;
			costUV = G[u][I].second;

			if (dis[u] + costUV < dis[v])
			{
				dis[v] = dis[u] + costUV;
				parent[v] = u;
				pq.push(pLL(dis[v], v));
			}
		}
	}
}

int main()
{
	//BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, u, v, w, p, child;
	//READ();
	//WRITE();
	SF("%d %d", &n, &m);

	for (I = 0; I <= n; I++)
		dis[I] = INF;

	for (I = 0; I < m; I++)
	{
		SF("%d %d %d", &u, &v, &w);
		G[u].push_back(pLL(v, w));
		G[v].push_back(pLL(u, w));
	}

	Dijkstra(1);

	if (dis[n] == INF)
	{
		PF("-1\n");
		return 0;
	}

	child = n;
	I = 1;
	while (1)
	{
		p = parent[child];
		//cout << "p = " << p << " child = " << child << NL;
		path[I] = p;

		if (p == 1)
			break;

		child = p;
		I++;
	}
	path[0] = n;

	for (K = I; K >= 0; K--)
		PF("%I64d ", path[K]);

	return 0;
}

/*
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
*/
