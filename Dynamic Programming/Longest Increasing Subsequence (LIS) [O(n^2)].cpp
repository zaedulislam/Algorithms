// Longest Increasing Subsequence (LIS).cpp
// Time Complexity: O(n^2)

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define NL '\n'
#define SF scanf
#define PF printf
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))


const int SIZE = 1e3 + 10;
int ar[SIZE], dp[SIZE], parent[SIZE];

int LIS(int u, int n)
{
	if(dp[u] != -1)
		return dp[u];

	int v, res, mx = 0;
	for(v = u + 1; v <= n; v++)	// 1st Condition, v > u
	{
		if(ar[v] > ar[u])				   // 2nd Condition, ar[v] > ar[u]
		{
			res = LIS(v, n);
			if(res > mx)					// Take the maximum
			{
				mx = res;
				parent[u] = v;
			}
		}
	}

	dp[u] = 1 + mx;	// Extra 1 is added becasue u is also included in the path
	return dp[u];
}

void PrintPath(int start)
{
	while(parent[start] != -1)
	{
		PF("%d ", ar[start]);
		start = parent[start];
	}
	PF("%d\n", ar[start]);
}

int main()
{
	int tcases, I, J, K, N, n, m, cnt = 0, len, res, u, start, lisLength;

	SET(parent);
	SET(dp);

	SF("%d", &n);
	for(I = 1; I <= n; I++)
		SF("%d", &ar[I]);

	lisLength = 0;
    for(u = 1; u <= n; u++)
	{
		res = LIS(u, n);
		if(res > lisLength)
		{
			lisLength = res;
			start = u;
		}
	}

	PF("%d\n", lisLength);

	PrintPath(start);

	return 0;
}

/*
Input:
7
5 0 9 2 7 3 4

Output:
4
0 2 3 4
*/
