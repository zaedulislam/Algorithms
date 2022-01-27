
#include<iostream>
using namespace std;
const int SIZE = 100;


void Merge(int *L, int nL, int *R, int nR, int *ar)
{
	int I = 0, J = 0, K = 0;

	while (I < nL && J < nR)
	{
		if (L[I] <= R[J])
		{
			ar[K] = L[I];
			K++;
			I++;
		}
		else
		{
			ar[K] = R[J];
			K++;
			J++;
		}
	}

	while (I < nL)
	{
		ar[K] = L[I];
		I++;
		K++;
	}

	while (J < nR)
	{
		ar[K] = R[J];
		J++;
		K++;
	}

}



void MergeSort(int *ar, int n)
{
	int mid, *left, *right;
	if (n < 2)
		return;

	mid = n / 2;
	left = new int[mid];
	right = new int[n - mid];

	for (int I = 0; I < mid; I++)
		left[I] = ar[I];
	for (int I = mid; I < n; I++)
		right[I - mid] = ar[I];

	MergeSort(left, mid);
	MergeSort(right, n - mid);
	Merge(left, mid, right, n - mid, ar);
	
	free(left);
	free(right);
}



int main()
{
	int I, n, ar[SIZE];
	cin >> n;
	for (I = 0; I < n; I++)
		cin >> ar[I];

	MergeSort(ar, n);

	cout << "Sorted Array: ";
	for (I = 0; I < n; I++)
		cout << ar[I] << ' ';
	cout << endl;

	return 0;
}

/*
Input:
8
2 4 1 6 8 5 3 7

Output:
Sorted Array: 1 2 3 4 5 6 7 8
*/