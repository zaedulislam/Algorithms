// Coin Change (Variant 1).cpp
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
const int SIZE = 100;

int coin[] = { 0, 2, 3 };
int dp[SIZE][SIZE], n = 2, make;

int coinChange(int pos, int amount)
{
	if (pos > n){
		if (amount == make)
			return 1;
		else
			return 0;
	}

	if (dp[pos][amount] != -1)
		return dp[pos][amount];

	int ret1 = 0, ret2 = 0;
	if (amount + coin[pos] <= make)
		ret1 = coinChange(pos, amount + coin[pos]);

	ret2 = coinChange(pos + 1, amount);

	return dp[pos][amount] = ret1 | ret2;
}


int main()
{
	///BOOST
	int tcases, I, J, K, N, m, cnt = 0, len;
	///READ();
	///WRITE();
	while (true)
	{
		SET(dp);

		SF("%d", &make);
		cout << coinChange(1, 0) << NL;
	}

	return 0;
}
