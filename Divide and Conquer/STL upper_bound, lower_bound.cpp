// STL upper_bound, lower_bound.cpp

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define NL '\n'
#define SF scanf
#define PF printf
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))


const int SIZE = 1e3 + 10;
int ar[SIZE] = {1, 2, 4, 4, 4, 6, 8, 8};
vector<int> vi;
set<int> si;


int main()
{
	int tcases, I, J, K, N, n, m, cnt = 0, len, x, idx;
	n = 8;
	cin >> x;

	idx = upper_bound(ar, ar + n, x) - ar;
	//cout << "Upper Bound: " << idx << NL;
	idx = lower_bound(ar, ar + n, x) - ar;
	//cout << "Lower Bound: " << idx << NL;

	for(I = 0; I < n; I++)
	{
		vi.push_back(ar[I]);
		si.insert(ar[I]);
	}

	idx = upper_bound(vi.begin(), vi.end(), x) - vi.begin();
	cout << "Upper Bound: " << idx << NL;
	idx = lower_bound(vi.begin(), vi.end(), x) - vi.begin();
	cout << "Lower Bound: " << idx << NL;

	return 0;
}

/*
7
5 0 9 2 7 3 4
*/
