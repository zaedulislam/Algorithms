// Kruskal's Algorithm (MST).cpp

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int SIZE = 1e5 + 5;
int parent[SIZE];




struct Edge
{
	int u, v, w;
};

vector<Edge> E, mst;



bool Compare(const Edge A, const Edge B)
{
	return A.w < B.w;
}



int Find(int r)
{
	if(r == parent[r])
		return r;

	int p = Find(parent[r]);
	return p;
}



void Kruskal(int n)
{
	sort(E.begin(), E.end(), Compare);

	int I, a, b, u, v, SZ, miniCost = 0, cnt = 0;
	for(I = 0; I <= n; I++)
		parent[I] = I;

	SZ = E.size();
	for(I = 0; I < SZ; I++)
	{
		a = E[I].u;
		b = E[I].v;

		u = Find(a);
		v = Find(b);

		if(u != v)
		{
			mst.push_back(E[I]);
			parent[u] = v;
			miniCost += E[I].w;
			cnt++;

			if(cnt == n - 1)
				break;
		}

	}

	cout << "Cost = " << miniCost << endl;

}



int main()
{
	int I, n, m, u, v, w;

	cin >> n >> m;
	for(I = 0; I < m; I++)
	{
		cin >> u >> v >> w;

		Edge info;
		info.u = u;
		info.v = v;
		info.w = w;

		E.push_back(info);
	}

	//cout << "SZ = " << E.size() << endl;

	Kruskal(n);

	return 0;

}

/*
Input:
7 11
1 2 7
2 3 8
3 5 5
2 5 7
5 7 9
5 6 8
6 7 11
4 5 15
2 4 9
1 4 5
4 6 6

Output:
Cost = 39

*/
