/*
Sliding Window/Two Pointers - Variant 3_1.cpp

Find the maximum sum of a certain sub-array and it's size K(Window Length). Examples:
For array A1 = {2, -5, [7, 8, -10, 15]}, the answer is 20 by summing the highlighted sub-array and K = 4.
For array A2 = {-5, [6, 8, -2, 20]}, the answer is 32 by summing the highlighted sub-array and K = 4.
*/

#include <iostream>
#include <cstdio>
#define NL '\n'
using namespace std;
const int SIZE = 1e6;
int ar[SIZE];




int main()
{
	int tcases, I, J, K, N, n, m, cnt = 0, len, currSum = 0, finalSum = 0, windowLength = 0, left = 0, right = 0;
	cin >> n;
    for(I = 0; I < n; I++)
		cin >> ar[I];

	for(I = 0; I < n; I++)
	{
		currSum += ar[I];

		if(currSum < 0)	/// Because it will lead to find the Maximum Sum.
			currSum = 0;

		if(currSum > finalSum)
			finalSum = currSum;
	}

	cout << "Maximum Sum = " << finalSum << NL;

	return 0;
}

/*
Input:
6
2 -5 7 8 -10 15

5
-5 6 8 -2 20

Output:
20
32
*/