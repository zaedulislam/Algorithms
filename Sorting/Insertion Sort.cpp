// Insertion Sort.cpp
// Complexity: O(n^2)

#include <bits/stdc++.h>
using namespace std;
const int SIZE = 100 + 10;
int ar[SIZE];




void InsertionSort(int N)
{
	int I, item, idx;
	for (I = 2; I <= N; I++) 		/// Starts with the second number
	{
		item = ar[I];
		idx = I - 1;

		while (idx >= 1 && ar[idx] > item)		/// Larger values move up
		{
 			ar[idx + 1] = ar[idx];
			idx--;
		}

		ar[idx + 1] = item;     	/// Put item into its proper position

	}

}



int main()
{
	int I, N;

	cin >> N;

	for(I = 1; I <= N; I++)
		cin >> ar[I];

	InsertionSort(N);

	for(I = 1; I <= N; I++)
		cout << ar[I] << ' ';

	printf("\n");

	return 0;
}

/*
13
9 94 45 47 28 98 65 42 78 4 11 88 6

*/


