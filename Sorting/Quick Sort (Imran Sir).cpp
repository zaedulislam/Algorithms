#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cctype>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
#include<algorithm>
#include<vector>
typedef unsigned long long llu;
using namespace std;

const int _size = 13;

int partition(int arr[], int left, int right)
{
	int pivot = arr[left], I = left, J = right + 1, temp;

	while (I < J){
		while (arr[I] <= pivot)
			I++;

		while (arr[J] > pivot)
			J--;
		
		if (J < I)
			break;

		temp = arr[I];
		arr[I] = arr[J];
		arr[J] = temp;
	}
	arr[left] = arr[J];
	arr[J] = pivot;

	return J;
}

void quick_sort(int arr[], int low, int high)
{
	if (low < high){
		int Index = partition(arr, low, high);
		quick_sort(arr, low, Index - 1);
		quick_sort(arr, Index + 1, high);
	}
}

int main(void)
{
	int arr[_size + 1] = { 9,94,45,47,28,98,65,42,78,4,11,88,6,32767 };
	quick_sort(arr, 0, _size - 1);
	
	int I;
	for (I = 0; I < _size; I++)
		printf("%d ", arr[I]);

	printf("\n");

	return 0;
}
