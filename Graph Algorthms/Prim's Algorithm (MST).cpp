// Prim's Algorithm (MST).cpp

/// Template by Zayed ///

///************************************************************///
/// #include <bits/stdc++.h>
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
//#include<unordered_map>
#include <set>
//#include<unordered_set>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdlib>
///************************************************************///
using namespace std;
int caseno = 1;
///************************************************************///
#define NL '\n'
#define SF scanf
#define PF printf
#define PC() printf("Case %d: ", caseno++)//NOTES:printf
//#define PC cout << "Case "//NOTES:cout
//#define CN cout << caseno++ << ": "//NOTES:cout
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define READ() freopen("input.txt", "r", stdin)
#define WRITE() freopen("output.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);
///************************************************************///
typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
///************************************************************///
#define INF (1 << 31) - 1
#define MOD 1000000007
#define PRIME 999998727899999 			// (largest prime below 10^16)
#define PB push_back
#define pii pair<int, int>
#define pic pair<int, char>
#define pci pair<char, int>
#define pLL pair<LL, LL>
#define pis pair<int, string>
#define psi pair<string, int>
#define pss pair<string, string>
#define PI 2 * acos(0.0)
#define EPS 1e-11
///************************************************************///
// Numeric Functions
template < class T > inline void SWAP(T &a, T &b) { T t = a; a = b; b = t; }
inline LL POW(LL base, LL power){
	LL res = base; if (power == 0) return 1;
	for (int I = 0; I < power - 1; I++) res *= base; return res;
}
// Translator Functions
int ToInt(string s) { int r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:ToInt(
double ToDouble(string s) { double r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:ToDouble(
string ToString(int n) { string s; stringstream convert; convert << n; s = convert.str(); return s; }//NOTES:ToString(
///************************************************************///

/*
*******4 Direction Array*******
int dx[] = {0, 0, - 1, 1}, dy[] = {-1, 1, 0, 0};
*******8 Direction Array*******
int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1};
********Knight Moves********
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};
*/

const int SIZE = 1e5;
vector<pii> G[SIZE];
int cost[SIZE], taken[SIZE];
int totalCost = 0;
vector<int> mst;

struct Node
{
	int a, cost;
	Node(){}
	Node(int _a, int _cost)
	{
		a = _a;
		cost = _cost;

	}

};

bool operator<(Node A, Node B)
{
	return A.cost > B.cost;
}

priority_queue<Node> PQ;


void PRIM(int src, int N)
{
	int I;
	for (I = 0; I <= N; I++)
	{
		cost[I] = INF;
		taken[I] = 0;
	}


	cost[src] = 0;
	PQ.push(Node(src, 0));

	int u, v, costU, costV;

	while (!PQ.empty())
	{

		Node node = PQ.top();
		u = node.a;
		costU = node.cost;
		PQ.pop();


		if (taken[u] == 1)
			continue;
		else
			mst.PB(u);

		taken[u] = 1;
		totalCost += costU;


		int SZ = G[u].size();
		for (I = 0; I < SZ; I++)
		{
			pii temp = G[u][I];
			v = temp.first;
			costV = temp.second;

			if (taken[v] == 1)
				continue;
			if (costV < cost[v])
			{
				PQ.push(Node(v, costV));
				cost[v] = costV;
			}

		}

	}

}


int main()
{
	///BOOST
	///READ();
	///WRITE();
	int T, I, J, K, N, n, m, cnt = 0, len, u, v, w;

	SF("%d%d", &n, &m);

	for (I = 0; I < m; I++)
	{
		SF("%d%d%d", &u, &v, &w);

		G[u].PB(pii(v, w));
		G[v].PB(pii(u, w));

	}

	PRIM(1, n);

	cout << "Total Cost =  " << totalCost << NL;
	for (I = 1; I <= n; I++)
		cout << I << " = " << cost[I] << NL;

	cout << "MST: ";
	for(I = 0; I < mst.size(); I++)
		cout << mst[I] << ' ';
	cout << NL;

	return 0;
}

/*
6 9
1 2 6
1 5 5
2 5 7
2 3 1
5 4 14
5 3 8
3 4 9
3 6 2
4 6 3

6 9
1 2 5
1 5 6
2 5 1
2 3 7
5 4 14
5 3 8
3 4 2
3 6 9
4 6 2

*/




