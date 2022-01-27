// UVa 1213 - Sum of Different Primes.cpp

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
#define PC() printf("Case %d: ", caseno++)//NOTES:printf
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


const int SIZE = 1120 + 10;
bool status[SIZE];
vector<int> prime;
int dp[189 + 5][SIZE][14 + 5], n, k, SZ;




void Sieve()
{
	int I, K, sqrtN = (int)sqrt((double)SIZE);

	for(I = 3; I <= sqrtN; I+= 2)
	{
		if(status[I] == false)
		{
			for(K = I * I; K <= SIZE; K += 2 * I)
				status[K] = true;

		}

	}

	prime.PB(2);
	for(I = 3; I <= SIZE; I += 2)
	{
		if(status[I] == false)
			prime.PB(I);

	}

}



int F(int pos, int taken, int cnt)
{
	if(pos >= SZ || taken > n || cnt > k)
		return 0;

	if(taken == n && cnt == k)
		return 1;

	if(dp[pos][taken][cnt] != -1)
		return dp[pos][taken][cnt];

	int ret1 = 0, ret2 = 0;
	
	if(taken + prime[pos] <= n)
		ret1 = F(pos + 1, taken + prime[pos], cnt + 1);
		
	ret2 = F(pos + 1, taken, cnt);

	dp[pos][taken][cnt] = ret1 + ret2;
	return dp[pos][taken][cnt];
}



int main()
{
	///BOOST
	///READ();
	///WRITE();
	int T, I, J, K, N, m, len;

	Sieve();
	SZ = prime.size();

	while(1)
	{
		SET(dp);

		SF("%d%d", &n, &k);

		if(n == 0 && k == 0)
			break;

		int ret = F(0, 0, 0);
		PF("%d\n", ret);

	}

	return 0;

}




