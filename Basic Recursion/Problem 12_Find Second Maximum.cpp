/*
Problem 12_Find Second Maximum.cpp
Write a recursive solution to find the second maximum number from a given set of integers.
*/

#include <bits/stdc++.h>
using namespace std;
#define INTMAX (-1) * ((1LL << 31) - 1)
const int SIZE = 100;




int FindSecondMax(int pos, int *ar, int secondMx, int mx, int N)
{
	if(N == 1)
		return ar[0];
	if(pos >= N)
		return secondMx;

	if(ar[pos] > mx)
	{
		secondMx = mx;
		mx = ar[pos];
	}
	else if(ar[pos] > secondMx && ar[pos] < mx)
		secondMx = ar[pos];

	int ret = 0;
	ret = FindSecondMax(pos + 1, ar, secondMx, mx, N);

	return ret;

}



int main()
{
	int ar[SIZE], I, N;

	cin >> N;

	for(I = 0; I < N; I++)
		cin >> ar[I];

	cout << FindSecondMax(0, ar, INTMAX, INTMAX, N) << '\n';

	return 0;

}


/*
Input:
5
5 8 7 9 3
Output:
8
*/
