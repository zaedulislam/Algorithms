// TimusOJ 1005 - Stone Pile.cpp
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

template <class T> T fABS(T a) { return a < 0 ? a * (-1) : a; }
template <class T> T MIN(T a, T b) { return a < b ? a : b; }

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 60;

int ar[SIZE], total;

int func(int pos, int taken, int n)
{
	if(pos == n)
	{
		int x = fABS((taken - (total - taken)));

		return x;
	}

	int profit1 = 0, profit2 = 0, mn;
	profit1 = func(pos + 1, taken + ar[pos], n);
	profit2 = func(pos + 1, taken, n);

	mn = MIN(profit1, profit2);
	return mn;
}

int main()
{
	BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len;
	///READ();
	///WRITE();
	cin >> n;

	total = 0;
	for(I = 0; I < n; I++)
	{
		cin >> ar[I];
		total += ar[I];
	}

	cout << func(0, 0, n);

	return 0;
}

