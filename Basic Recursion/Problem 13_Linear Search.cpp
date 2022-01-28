/*
Problem 13_Linear Search.cpp
Implement linear search recursively, i.e. given an array of integers, find a specific value from it.
Input format: first n, the number of elements. Then n integers. Then, q, number of query, then q integers.
Output format: for each of the q integers, print its index (within 1 to n) in the array or
print 'Not found', whichever is appropriate.
*/

#include <bits/stdc++.h>
using namespace std;
const int SIZE = 100;




int LinearSearch(int pos, int value, int *ar, int N)
{
	if(pos == N)
		return -1;

	int ret = 0;

	if(ar[pos] == value)
		ret = pos;
	else
		ret = LinearSearch(pos + 1, value, ar, N);

	return ret;

}



int main()
{
	int ar[SIZE], I, N, q, m, ret;

	cin >> N;
	for(I = 1; I <= N; I++)
		cin >> ar[I];

	cin >> q;
	for(I = 0; I < q; I++)
	{
		cin >> m;

		ret = LinearSearch(1, m, ar, N);

		if(ret == -1)
			cout << "Not found\n";
		else
			cout << ret << '\n';

	}

	return 0;
}


/*
Input:
5
2 9 4 7 6
2
5 9
Output:
Not found
2
*/
