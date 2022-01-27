// Longest Increasing Subsequence (LIS).cpp
// Time Complexity: O(nlogn)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define SF scanf
#define PF printf
#define SET(ar) memset(ar, -1, sizeof(ar))


const int SIZE = 1e6 + 10;
int ar[SIZE], parent[SIZE];	//Tracking the predecessors/parents of elements of each subsequence.
vector<int> vi, increasingSub;	// Tracking ends of each increasing subsequence.


int BinarySearch(int value)
{
	int first = 0, last = vi.size() - 1, mid, pos, idx;
	while (first <= last)
	{
		mid = (first + last) / 2;
		idx = vi[mid];

		if (ar[idx] == value)
			return mid;
		else if (ar[idx] > value)
			last = mid - 1;
		else if (ar[idx] < value)
			first = mid + 1;
	}

	/*
	Observe the binary search carefully, when the binary search ends first > last and we put our item in
	vi[first].
	*/
	pos = first;
	return first;
}

int LIS(int n)
{
	int I, x, idx;
	for (I = 0; I < n; I++)
	{
		x = ar[I];

		if (vi.size() == 0)
			vi.push_back(I);
		else
		{

			idx = BinarySearch(x);

			if (idx == vi.size())
				vi.push_back(I);
			else
				vi[idx] = I;

			// update parent/previous element for LIS
			if(idx != 0)
				parent[I] = vi[idx - 1];

		}

	}
	// Size of the vector increasingSub, represents the length of the LIS.
	return vi.size();
}

void PrintLIS()
{
	// Generate LIS by traversing parent array.
	int I, SZ, start = vi[vi.size() - 1];

	while (parent[start] != -1)
	{
		increasingSub.push_back(ar[start]);
		start = parent[start];
	}
	increasingSub.push_back(ar[start]);

	SZ = increasingSub.size();

	PF("%d", increasingSub[SZ - 1]);
	for (I = SZ - 2; I >= 0; I--)
		PF(" %d", increasingSub[I]);

	PF("\n");
}


int main()
{
	int tcases, I, J, K, N, n, m, cnt = 0, len, res, u, lisLength;

	SET(parent);

	SF("%d", &n);
	for (I = 0; I < n; I++)
		SF("%d", &ar[I]);

	lisLength = LIS(n);
	PF("%d\n", lisLength);

	PrintLIS();

	return 0;
}

/*
Input:
8
5 0 9 2 2 7 3 4

7
3 1 5 2 6 4 9
Output:
4
0 2 3 4

4
1 2 4 9
*/
