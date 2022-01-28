/*
Problem 14_Binary Search.cpp
Implement binary search recursively, i.e. given an array of sorted integers, find a query integer from it.
Input format: first n, the number of elements. Then n integers. Then, q, number of query, then q integers.
Output format: for each of the q integers, print its index (within 1 to n) in the array or
print 'Not found', whichever is appropriate.
*/

#include <bits/stdc++.h>
using namespace std;
const int SIZE = 100;




int BinarySearch(int first, int last, int value, int *ar)
{
	if(first > last)
		return -1;

	int ret = 0, mid = (first + last) / 2;
	if(ar[mid] == value)
		ret = mid;
	else if(ar[mid] > value)
		ret = BinarySearch(first, mid - 1, value, ar);
	else
		ret = BinarySearch(mid + 1, last, value, ar);

	return ret;
}



int main()
{
	int ar[SIZE], I, N, q, m, ret;

	cin >> N;
	for(I = 1; I <= N; I++)
		cin >> ar[I];

	cin >> q;
	for(I = 0; I < q; I++)
	{
		cin >> m;

		ret = BinarySearch(1, N, m, ar);

		if(ret == -1)
			cout << "Not found\n";
		else
			cout << ret << '\n';

	}

	return 0;
}


/*
Input:
5
1 2 3 4 5
2
3 -5
Output:
2
Not found
*/