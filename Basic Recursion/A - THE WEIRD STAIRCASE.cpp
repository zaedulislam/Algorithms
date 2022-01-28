// A - THE WEIRD STAIRCASE.cpp
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

template <class T> inline T MIN(T a, T b){ return (a < b) ? a : b; }

typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 50;

int ar[SIZE], n, mn;

int recurse(int pos, int cnt)
{
	if (cnt > n || pos > n || pos < 0)
		return  INF;
	if (pos == n)
		return cnt;

	int ret1 = 0, ret2 = 0;
	ret1 = recurse(pos + 1, cnt + 1);
	ret2 = recurse(pos + ar[pos], cnt + 1);
	mn = MIN(mn, MIN(ret1, ret2));
	return mn;
}

int main()
{
	///BOOST
	int tcases, I, J, K, N, m, cnt = 0, len;
	///READ();
	///WRITE();
	SF("%d", &tcases);
	while (tcases--)
	{
		SF("%d", &n);
		for (I = 0; I < n; I++)
			SF("%d", &ar[I]);

		if (n == 1)
		{
			PF("1\n");
			continue;
		}
			
		mn = INF;
		PF("%d\n", recurse(0, 0));
	}

	return 0;
}

/*
3
2
1 -1

6
-1 2 1 3 -3 3

10
5 1 1 1 6 -1 1 1 1 1
*/