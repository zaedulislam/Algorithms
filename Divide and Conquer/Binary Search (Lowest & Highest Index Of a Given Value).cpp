// Binary Search (Lowest & Highest Index Of a Given Value).cpp
#include <iostream>
#include <cstdio>
using namespace std;
const int SIZE = 1e3;
int ar[] = { 1, 2, 3, 3, 4, 4, 4, 4, 5, 9, 20, 20, 21, 21, 21 };

int lowestIndex(int value)
{
	int mid, index = -1, first = 0, last = 14;
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (ar[mid] == value)
		{
			// One occurance of the value is found, save the index.
			index = mid;
			// Continue searching the left portion after one occurrence is found.
			last = mid - 1;
		}
		else if(ar[mid] > value)
			last = mid - 1;
		else
			first = mid + 1;
	}
	return  index;
}

int highestIndex(int value)
{
	int mid, index = -1, first = 0, last = 14;
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (ar[mid] == value)
		{
			// One occurance of the value is found, save the index.
			index = mid;
			// Continue searching the right portion after one occurrence is found.
			first = mid + 1;
		}
		if (ar[mid] > value)
			last = mid - 1;
		else
			first = mid + 1;
	}
	return index;
}

int main()
{
	int tcases, caseno = 1, n, I, J, K, N, cnt = 0, len, index;
	while (scanf("%d", &n), (n || 0))
	{
		index = lowestIndex(n);
		cout << "Lowest Index of " << n << " is: " << index << endl;

		index = highestIndex(n);
		cout << "Highest Index of " << n << " is: " << index << endl;
	}
	return 0;
}

/*
INPUT
4
1
OUTPUT
4
7

0
0
*/
