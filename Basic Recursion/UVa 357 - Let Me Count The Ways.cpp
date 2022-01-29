// UVa 357 - Let Me Count The Ways.cpp
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
const int SIZE = 30000 + 10;

LL coin[] = {1, 5, 10, 25, 50}, dp[5 + 2][SIZE], way, make, N;

LL func(LL pos, LL taken)
{
	if(pos >= 5)
	{
		if(taken == 0)
			return 1;
		else
			return 0;
	}

	if(dp[pos][taken] != -1)
		return dp[pos][taken];

	LL ret1 = 0, ret2 = 0;

	if(taken - coin[pos] >= 0)
		ret1 = func(pos, taken - coin[pos]);

	ret2 = func(pos + 1, taken);

	dp[pos][taken] = ret1 + ret2;
	return dp[pos][taken];
}

int main()
{
	///BOOST
	LL tcases, I, J, K, n, m, cnt = 0, len;
	///READ();
	///WRITE();

	SET(dp);

	while(SF("%lld", &make) != EOF)
	{
		N = make;
		way = func(0, make);

		if(way == 1)
			PF("There is only 1 way to produce %lld cents change.\n", N);
		else
			PF("There are %lld ways to produce %lld cents change.\n", way, N);
	}

	return 0;
}

