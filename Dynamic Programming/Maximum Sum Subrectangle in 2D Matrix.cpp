/*
Maximum Sum Subrectangle in 2D Matrix.cpp
Given a 2D array, find the maximum sum subarray in it. This problem is mainly an extension of Largest Sum
Contiguous Subarray for 1D array.

Time Complexity: O(n^3)
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define NL '\n'
#define SF scanf
#define PF printf

const int SIZE = 110;

int M[SIZE][SIZE], ar[SIZE];

int main()
{
	int tcases, I, J, K, N, R, C, n, m, cnt = 0, len, left = 0, right = 0, row = 0, finalSum = 0, up = 0, down = 0,
	currSum = 0, maxSum = 0, maxLeft = 0, maxRight = 0, maxUp = 0, maxDown = 0, tempUp = 0;

	SF("%d%d", &R, &C);
	for (I = 0; I < R; I++)
	{
		for (K = 0; K < C; K++)
			SF("%d", &M[I][K]);
	}

	// Set the left column
	for (I = 0; I < C; I++)
	{
		// Initialize all elements of ar as 0
		memset(ar, 0, sizeof(ar));

		left = I;
		// Set the right column for the left column set by outer loop
		for (right = I; right < C; right++)
		{

			// Calculate sum between current left and right for every row 'row'
			for (row = 0; row < R; row++)
				ar[row] += M[row][right];

			/*
			Implementation of Kadane's algorithm for 1D array->->->.
			*/
			currSum = 0;
			for (J = 0; J < R; J++)
			{
				currSum += ar[J];

				if (currSum < 0)
				{
					currSum = 0;
					tempUp = J + 1;
				}

				if (currSum > maxSum)
				{
					maxSum = currSum;
					up = tempUp;
					down = J;
				}

			}

			/*
			Implementation of Kadane's algorithm for 1D array->->->.
			*/

			/*
			Compare finalSum with maxSum so far. If maxSum is more, then update finalSum and other output values
			*/
			if (maxSum > finalSum)
			{
				finalSum = maxSum;
				maxLeft = left;
				maxRight = right;
				maxUp = up;
				maxDown = down;
			}

		}

	}

	PF("Maximum Sum is: %d\n", finalSum);
	PF("Sub-rectangle is:\n(left, right) = (%d, %d)\n(up, down) = (%d, %d)\n", maxLeft, maxRight, maxUp, maxDown);

	return 0;
}

/*
Input:
4 4
0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2

4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6

4 5
2 1 -3 -4 5
0 6 3 4 1
2 -2 -1 4 -5
-3 3 1 0 3

Output:
Maximum Sum is: 15
Sub-rectangle is:
(left, right) = (0, 1)
(up, down) = (1, 3)

Maximum Sum is: 29
Sub-rectangle is:
(left, right) = (1, 3)
(up, down) = (1, 3)

Maximum Sum is: 18
Sub-rectangle is:
(left, right) = (1, 3)
(up, down) = (1, 3)
*/

