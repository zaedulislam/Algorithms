// Binary Search (Recursive).cpp

#include <iostream>
using namespace std;



int ar[] = { 1, 5, 6, 8, 9, 10, 15, 56, 78, 90 };



int  BinarySearch(int first, int last, int val)
{
	int ret = -1, mid = (first + last) / 2;

	if (first > last)
		return -1;
	if (ar[mid] == val)
		return mid;
	else if (ar[mid] < val)
		ret = BinarySearch(mid + 1, last, val);
	else if (ar[mid] > val)
		ret = BinarySearch(first, mid - 1, val);

	return ret;
}



int main()
{
	int val, n = sizeof(ar) / 4, pos;

	cin >> val;

	pos = BinarySearch(0, n - 1, val);

	if (pos == -1)
		cout << "Value Not Found!" << endl;
	else
		cout << "Value Found at Position " << pos << '.' << endl;

	return 0;
}
