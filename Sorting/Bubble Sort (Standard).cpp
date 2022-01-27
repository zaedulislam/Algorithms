// Bubble Sort (Standard).cpp
// Complexity: O(n^2)

#include<iostream>
using namespace std;
const int SIZE = 100;
int ar[SIZE];

template<class T>inline void SWAP(T &a, T &b) { T t = a; a = b; b = t; }




void BubbleSort(int n)
{
	int I, K;
	for (I = 0; I < n - 1; I++)     /// (n - 1) -> last element of the array will already be sorted.
	{
		for (K = 0; K < n - 1; K++)      /// (n - 1) -> while comparing, K + 1 won't cross  the bound
		{
			if (ar[K] > ar[K + 1])
				SWAP(ar[K], ar[K + 1]);
		}
	}
}



int main()
{
	int I, n;
	cin >> n;
	for (I = 0; I < n; I++)
		cin >> ar[I];

	BubbleSort(n);

	cout << "Sorted Array: ";
	for (I = 0; I < n; I++)
		cout << ar[I] << " ";

	return 0;
}

/*
Input:
5
41 85 72 38 80

Output:
Sorted Array: 38 41 72 80 85
*/