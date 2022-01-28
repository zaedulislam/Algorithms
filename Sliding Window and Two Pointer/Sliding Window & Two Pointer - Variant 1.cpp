/*
Sliding Window & Two Pointers - Variant 1.cpp

Find the smallest sub-array size (smallest window length) so that the sum of the subarray is
greater than or equal to a certain constant S in O(n)? Examples:
For array A1 = {5, 1, 3, [5, 10], 7, 4, 9, 2, 8} and S = 15, the answer is 2 as highlighted.
For array A2 = {1, 2, [3, 4, 5]} and S = 11, the answer is 3 as highlighted.
*/
#include <iostream>
#include <cstdio>
#define NL '\n'
using namespace std;

const int SIZE = 1e6;
int ar[SIZE];




int main()
{
	int tcases, caseno = 1, n, I, J, K, N, cnt = 0, len, S, currSum = 0, windowLength = SIZE, left = 0;
	cin >> n >> S;
	for (I = 0; I < n; I++)
		cin >> ar[I];

	for (I = 0; I < n; I++)
	{
		currSum += ar[I];
		cnt++;
		while (currSum - ar[left] > S)
		{
			if (I - left < windowLength)
				windowLength = I - left;

			currSum -= ar[left];
			cnt--;
			left++;
		}
	}

	cout << windowLength << NL;

	return 0;
}

/*
Input:
5 11
1 2 3 4 5

10 15
5 1 3 5 10 7 4 9 2 8

Output:
3
2
*/