// Classical 0 -1 Knapsack.cpp
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

template <class T> inline T MAX(T &a, T &b) { return a > b ? a : b; }

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e4;

int weight[SIZE], cost[SIZE], dp[SIZE][SIZE], n, CAP;

int func(int pos, int taken)
{
	if (pos >= n)	/// All the objects are taken.
		return 0;

	if (dp[pos][taken] != -1)			/// This state have already calculated.
		return dp[pos][taken];

	int profit1 = 0, profit2 = 0;

	if (taken + weight[pos] <= CAP)		/// If the i'th object is taken then the profit will be "profit1".
		profit1 = cost[pos] + func(pos + 1, taken + weight[pos]);

	profit2 = func(pos + 1, taken);			/// If the i'th object is not taken then the profit will be "profit2".

	dp[pos][taken] = MAX(profit1, profit2);		/// We will take the maximum profit.
	return dp[pos][taken];
}

int main()
{
	///BOOST
	int tcases, I, J, K, N, m, cnt = 0, len;
	///READ();
	///WRITE();
	SET(dp);

	SF("%d %d", &n, &CAP);

	for(I = 0; I < n; I++)
		SF("%d %d", &weight[I], &cost[I]);

	PF("%d\n", func(0, 0));

	return 0;
}


/// n CAPACITY
/// WEIGHT COST
/*
4 10
1 120
4 280
3 150
4 200
*/

/*
4 500
100 2
100 3
200 3
400 4
*/

