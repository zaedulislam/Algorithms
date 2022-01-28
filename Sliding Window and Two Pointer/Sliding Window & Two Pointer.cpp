/*
Given two arrays (A and B) sorted in ascending order, and an integer x.
we need to find i and j, such that a[i] + b[j] is equal to X.Examples:
For array A1 = {1, 2, 3, [4]} , A2 = {4, [6]} and x = 10 ,the answer is 4 and 2 as highlighted.
*/

#include <iostream>
#include <cstdio>
#define NL '\n'

using namespace std;
const int SIZE = 1e6;
int a[SIZE], b[SIZE];




int main()
{
	int tcases, I, J, K, N, n, m, cnt = 0, len, x;
	cin >> n >> m >> x;
	for(I = 0; I < n; I++)
		cin >> a[I];
	for(I = 0; I < m; I++)
		cin >> b[I];

	I = 0, J = m - 1;
	while(I < n)
	{
		while(J > 0 && a[I] + b[J] > x)  /// Because what we need must be at a
			J--;						/// position less than current position of j or more than current position of i.
		if(a[I] + b[J] == x)
		{
			cout << I << " " << J << NL;
			break;
		}
		I++;
	}

	return 0;
}

/*
Input:
4 2 10
1 2 3 4
5 6

Output:
3 1
*/