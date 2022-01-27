// LightOJ 1164 - Horrible Queries.cpp

/// Template by Zayed ///

/// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>

#include <string>
#include <cstring>
#include <sstream>

//#include <tuple>
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

using namespace std;
int caseno = 1;

#define NL '\n'
#define SF scanf
#define PF printf
#define PC() printf("Case %d:\n", caseno++)//NOTES:printf
//#define PC cout << "Case "//NOTES:cout
//#define CN cout << caseno++ << ": "//NOTES:cout
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define READ() freopen("input.txt", "r", stdin)
#define WRITE() freopen("output.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"

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
//#define tiii tuple<int, int, int>
#define PI 2 * acos(0.0)
#define EPS 1e-11


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


/*
*******4 Direction Array*******
int dx[] = {0, 0, - 1, 1}, dy[] = {-1, 1, 0, 0};
*******8 Direction Array*******
int dx[] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[] = {-1, +1, 0, 0, -1, +1, -1, +1};
********Knight Moves********
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};
*/


const int SIZE = 1e5 + 10;
int tree[4 * SIZE], lazy[4 * SIZE];




void lazyUpdate(int node, int b, int e, int I, int J, int delta)
{
	if(b > e)
		return;

	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (b + e) / 2;

	if(lazy[node] != 0)
	{
		tree[node] += lazy[node];

		if(I != J)
		{
			lazy[left] += lazy[node];
			lazy[right] += lazy[node];
		}

		lazy[node] = 0;
	}


	if(b > J || e < I)
		return;


	if(b >= I && e <= J)
	{
		tree[node] += delta;

		if(I != J)
		{
			lazy[left] += delta;
			lazy[right] += delta;
		}

		return;
	}


	lazyUpdate(left, b, mid, I, J, delta);
	lazyUpdate(right, mid + 1, e, I, J, delta);

	tree[node] = tree[left] + tree[right];
}



int Query(int node, int b, int e, int I, int J)
{
	if(b > e)
		return 0;

	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (b + e) / 2;


	if(lazy[node] != 0)
	{
		tree[node] += lazy[node];

		if(I != J)
		{
			lazy[left] += lazy[node];
			lazy[right] += lazy[node];
		}

		lazy[node] = 0;
	}


	if(b > J || e < I)
		return 0;

	if(b >= I && e <= J)
		return tree[node];

	int ret1 = Query(left, b, mid, I, J);
	int ret2 = Query(right, mid + 1, e, I, J);

	return ret1 + ret2;
}



int main()
{
	///BOOST
	///READ();
	///WRITE();
	int T, I, J, K, N, n, m, k, cnt = 0, len, x, y, v, q;

	SF("%d", &T);

	while(T--)
	{

		CLR(tree);
		CLR(lazy);

		SF("%d%d", &n, &q);

		PC();

		for(I = 1; I <= q; I++)
		{
			SF("%d", &m);

			if(m == 0)
			{
				SF("%d%d%d", &x, &y, &v);
				x++, y++;

				lazyUpdate(1, 1, n, x, y, v);

			}
			else
			{
				SF("%d%d", &x, &y);
				x++, y++;

				PF("%d\n", Query(1, 1, n, x, y));

			}

		}

	}

	return 0;
}




