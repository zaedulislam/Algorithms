// Sort Using a Single Loop.cpp

#include <iostream>
#include <algorithm>
using namespace std;

int ar[100];




void SingleLoopSort(int n)
{
	int I = 0, J = 0;
	while(I < n - 1)
	{
		if (ar[J] > ar[J + 1])
			swap(ar[J], ar[J + 1]);
		
		J++;

		if (J == n - 1)
		{
			J = 0;
			I++;
		}
	}
}



int main()
{
	int I, n;
	cin >> n;
	for (I = 0; I < n; I++)
		cin >> ar[I];

	F(n);
	cout << "After Sorting: ";
	for (I = 0; I < n; I++)
		cout << ar[I] << ' ';

	return 0;
}

/*
5
5 4 3 2 1
*/