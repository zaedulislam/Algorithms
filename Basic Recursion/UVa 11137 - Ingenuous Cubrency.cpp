// UVa 11137 - Ingenuous Cubrency.cpp
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

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1e4 + 2;

int coin[] = {1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 1331, 1728, 2197, 2744, 3375, 4096, 4913, 5832, 6859, 8000, 9261};
LL dp[20 + 2][SIZE], N = 21;

LL func(int pos, int make)
{
	if(pos >= N)
	{
		if(make == 0)
			return 1;
		else
			return 0;
	}

	if(dp[pos][make] != -1)
		return dp[pos][make];

	LL ret1 = 0, ret2 = 0;

	if(make - coin[pos] >= 0)
		ret1 = func(pos, make - coin[pos]);

	ret2 = func(pos + 1, make);

	dp[pos][make] = ret1 + ret2;
	return dp[pos][make];
}

int main()
{
	///BOOST
	int tcases, I, J, K, n, m, cnt = 0, len, make;
	///READ();
	///WRITE();

	SET(dp);

	while(SF("%d", &make) != EOF)
	{
		PF("%lld\n", func(0, make));
	}

	return 0;
}

