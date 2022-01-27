/*
Quick Sort.cpp

Best Case Complexity: O(nlog(n))
Average Case Complexity: O(nlog(n))
Worst Case Complexity: O(n^2)

Space Complexity:
*/

#include<iostream>
using namespace std;




int Partition(int ar[], int start, int ed)
{
	int pivot = ar[start];
	int pivotIndex = start;
	int I = start + 1, J = ed;

	while(I <= J)
	{
		if(ar[I] > ar[J])
			swap(ar[I], ar[J]);
		if(ar[I] < pivot)
			I++;
		if(ar[J] > pivot)
			J--;
	}

	swap(ar[pivotIndex], ar[J]);
	return J;
}



void QuickSort(int ar[], int start, int ed)
{
	if(start >= ed)
		return;

	int pivotIndex = Partition(ar, start, ed);
	QuickSort(ar, 0, pivotIndex - 1);
	QuickSort(ar, pivotIndex + 1, ed);
}



int main()
{
	int ar[100], I, n;

	cin >> n;
	for(I = 0; I < n; I++)
		cin >> ar[I];

    QuickSort(ar, 0, n - 1);

    cout << "Sorted Array: ";
    for(I = 0; I < n; I++)
		cout << ar[I] << ' ';
	cout << '\n';

	return 0;
}

/*
Input:
8
2 4 1 6 8 5 3 7

Output:
Sorted Array: 1 2 3 4 5 6 7 8
*/
