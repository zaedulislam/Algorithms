// UVa 10664 - Luggage.cpp
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
const int SIZE = 50 + 10;

string S;
int ar[SIZE], dp[SIZE][200 + 10], total, n;

int func(int pos, int taken)
{
	if(pos >= n)
	{
		int x = total - taken;
		return abs(x - taken);
	}

	if(dp[pos][taken] != -1)
		return dp[pos][taken];

	int profit1 = 0, profit2 = 0;
	profit1 = func(pos + 1, taken + ar[pos]);
	profit2 = func(pos + 1, taken);

	dp[pos][taken] = min(profit1, profit2);
	return dp[pos][taken];
}

int main()
{
	BOOST
	int tcases, I, J, K, N, m, cnt = 0, len, ans;
	///READ();
	///WRITE();
	cin >> tcases;
	cin.ignore();

	while(tcases--)
	{
		SET(dp);
		memset(ar, 0, sizeof(ar));

		getline(cin, S);

		/// ***Convert the string to array of integers*** ///
		stringstream convert(S);

		n = 0;
		while(convert >> ar[n++]) {}
		n--;

		/// ***Convert the string to array of integers*** ///

		total = 0;
		for(I = 0; I < n; I++)
			total += ar[I];

		ans = func(0, 0);

		if(ans == 0)
			cout << "YES\n";
		else
			cout << "NO\n";

		///cout << NL;
	}

	return 0;
}

