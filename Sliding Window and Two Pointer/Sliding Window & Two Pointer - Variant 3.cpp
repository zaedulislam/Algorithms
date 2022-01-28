/*
Sliding Window/Two Pointers - Variant 3.cpp

Find the maximum sum of a certain sub-array with (static) size K(Window Length). Examples:
For array A1 = {10, [50, 30, 20], 5, 1} and K = 3, the answer is 100 by summing the highlighted sub-array.
For array A2 = {49, 70, 48, [61, 60], 60} and K = 2, the answer is 121 by summing the highlighted sub-array.
For array A1 = {2, -5, 7, [8, -10, 15]} and K = 3, the answer is 13 by summing the highlighted sub-array.
Complexity: O(n)
*/

#include <iostream>
#include <cstdio>
#define NL '\n'
using namespace std;
const int SIZE = 1e6;
int ar[SIZE];




int main()
{
	int tcases, I, J, K, N, n, m, cnt = 0, len, currSum = 0, finalSum = 0, left, right;
	cin >> n >> K;
    for(I = 0; I < n; I++)
		cin >> ar[I];

	for(I = 0; I < K; I++)
		currSum += ar[I];

	right = K - 1;
	finalSum = currSum;
    I = 0, J = K;
    while(J < n) /// This while loop will run for n - K times.
	{
		currSum -= ar[I];
		currSum += ar[J];
		I++, J++;

		if(currSum > finalSum)
		{
			finalSum = currSum;
			left = I, right = J - 1;
		}
	}

	if(finalSum <= 0)
		cout << 0 << NL;
	else
		cout << "Maximum Sum = " << finalSum << " (From Index " << left << " to " << right << ")"<< NL;

	return 0;
}

/*
Input:
6 3
2 -5 7 8 -10 15

6 3
10 50 30 20 5 1

6 2
49 70 48 61 60 60

Output:
13
100
121
 */