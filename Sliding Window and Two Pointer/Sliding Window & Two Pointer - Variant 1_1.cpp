/*
Sliding Window/Two Pointers - Variant 1_1.cpp
Find the largest sub-array size (largest window length) so that the sum of the subarray is
less than or equal to a certain constant S in O(n)? Examples:
For array A1 = {3, [1, 2, 1]} and S = 5, the answer is 3 as highlighted.
For array A2 = {[2],  2, 3} and S = 3, the answer is 1 as highlighted.
Complexity: O(n)
*/

#include <iostream>
#include <cstdio>
#define NL '\n'
using namespace std;
template <class T> inline T MAX(T a, T b){ return (a > b) ? a : b; }
const int SIZE = 1e5 + 10;
int ar[SIZE];




int main()
{
	int tcases, I, J, K, N, n, m, cnt = 0, t, len, currSum = 0, left = 0, windowLength = 0;
	cin >> n >> t;
	for (I = 0; I < n; I++)
		cin >> ar[I];

	for (I = 0; I < n; I++)
	{
		currSum += ar[I];		/// Add item to current Sum.
		cnt++;
		/// The following while loop is to adjust the boundary of the current window of
		/// books. If a new book is added in the right and if the sum exceed given time
		/// we have to decrease the length of the window by removing element(s) from the left.
		while (currSum > t)
		{
			currSum -= ar[left]; 	/// Remove the leftmost element
			left++;								/// Increment left pointer
			cnt--;								/// At each iteration update ans with maximum book window length till now
		}
		windowLength = MAX(windowLength, cnt);
	}

	cout << windowLength << NL;

	return 0;
}

/*
Input:
4 5
3 1 2 1

3 3
2 2 3


5 11
1 2 3 4 5

Output:
3
1
4
*/