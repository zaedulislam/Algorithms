/*
Problem 11_Find Maximum.cpp
Suppose you are given an array of integers in an arbitrary order.
Write a recursive solution to find the maximum element from the array.
*/

#include <bits/stdc++.h>
using namespace std;
const int SIZE = 100;




int FindMax(int pos, int N, int *ar)
{
	if(pos == N - 1)
		return ar[pos];

	int ret = 0;
	ret = max(ar[pos], FindMax(pos + 1, N, ar));

	return ret;
}



int main()
{
	int ar[SIZE], I, N;

	cin >> N;
	for(I = 0; I < N; I++)
		cin >> ar[I];

	cout << FindMax(0, N, ar) << '\n';

	return 0;
	
}


/*
Input:
5
7 4 9 6 2
Output:
9
*/
