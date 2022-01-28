// G - Monkey Banana Problem.cpp
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
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define PC() printf("Case %d: ", caseno++)
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);

template < class T > inline T MAX(T a, T b) { return a > b ? a : b; }

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 100 + 10;

int M[SIZE << 1][SIZE], dp[SIZE << 1][SIZE], row, col, N;

int func(int I, int J)
{
	if (M[I][J] == 0)
		return 0;

	if (I < 0 || I > row || J < 0 || J > col)
		return 0;

	if (dp[I][J] != -1)
		return dp[I][J];

	int ret = (-1) * INF;
	ret = MAX(ret, (M[I][J] + func(I + 1, J)));

	if (I < (N - 1))
		ret = MAX(ret, (M[I][J] + func(I + 1, J + 1)));
	else if (J != 0)
		ret = MAX(ret, (M[I][J] + func(I + 1, J - 1)));

	dp[I][J] = ret;
	return dp[I][J];
}

int main()
{
	///BOOST
	int tcases, I, J, K, n, m, cnt = 0, len;
	///READ();
	///WRITE();
	///cout << INF << NL;
	SF("%d", &tcases);
	while (tcases--)
	{
		CLR(M);
		SET(dp);

		/// INPUT
		SF("%d", &N);

		/// Upper half
		for (I = 0; I < N - 1; I++)
		{
			for (K = 0; K <= I; K++)
				SF("%d", &M[I][K]);
		}

		/// Middle
		K = 0;
		for (I = 0; I < N; I++)
			SF("%d", &M[N - 1][K++]);

		/// Lower half
		J = 0;
		for (I = N - 1; I > 0; I--)
		{
			for (K = 0; K < I; K++)
				SF("%d", &M[N + J][K]);
			J++;
		}
		/// INPUT

		row = (N << 1) - 2;
		col = N - 1;

		PC();
		PF("%d\n", func(0, 0));

	}

	return 0;
}

