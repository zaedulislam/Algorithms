// Binary Search (Iterative).cpp

#include<iostream>
using namespace std;



int ar[] = { 1, 5, 6, 8, 9, 10, 15, 56, 78, 90 };



int  BinarySearch(int n, int val)
{
	int first = 0, last = n - 1, mid;

	while (first <= last)
	{
		mid = (first + last) / 2;

		if (ar[mid] == val)
			return mid;
		else if (ar[mid] < val)
			first = mid + 1;
		else if (ar[mid] > val)
			last = mid - 1;
	}

	return -1;
}



int main()
{
	int val, n = sizeof(ar) / 4, pos;

	cin >> val;

	pos = BinarySearch(n, val);

	if (pos == -1)
		cout << "Value Not Found!" << endl;
	else
		cout << "Value Found at Position " << pos << '.' << endl;

	return 0;
}
