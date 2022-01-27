// Selection Sort.cpp
// Complexity: O(n^2)

#include<iostream>
using namespace std;




void SelectionSort(int arr[], int n)
{
	// Step through each element of the array
	int I, K;
	for (I = 0; I < n - 1; I++) // Outer loop
	{
		// min is the index of the smallest element
		// we've encountered so far
		int pos = I;

		// Search through every element starting at StartIndex + 1
		for (K = I + 1; K < n; K++)   // Inner loop
		{
			// If the current element is smaller than our previously found smallest
			if (arr[K] < arr[pos])
				pos = K;			// Store the index in minIndex
		}

		// Swap  start element with our smallest element
		int temp = arr[I];
		arr[I] = arr[pos];
		arr[pos] = temp;

	}
}



// Function to print the Array Elements
void print(int arr[], int n)
{
	int I;
	for (I = 0; I < n; I++)
		cout << arr[I] << " ";
	cout << endl;

}



int main()
{
	int array[] = { 5, 9, 81, 1, 25, 3, 12, 6, 69 };

	cout << "Before Sorting: ";
	print(array, 9);
	
	SelectionSort(array, 9);
	
	cout << "After Sorting: ";
	print(array, 9);

	return 0;
}
