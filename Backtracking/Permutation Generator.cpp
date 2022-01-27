// Permutation Generator.cpp
// Algorithm Paradigm: Backtracking
// Time Complexity: O(n * n!)
// Note : The below solution prints duplicate permutations if there are
// repeating characters in input string.

#include <iostream>
using namespace std;
#define NL '\n'
const int SIZE = 100;
int ar[SIZE], number[SIZE];
bool used[SIZE];




void Permutation(int pos, int n)
{
	int I;
	if (pos == n)
	{
		for (I = 0; I < n; I++)
			cout << number[I] << ' ';

		cout << NL;
		return;
	}


	for (I = 0; I < n; I++)
	{
		if (used[I] == false)
		{
			used[I] = true;
			number[pos] = ar[I];
			Permutation(pos + 1, n);
			used[I] = false;
		}

	}

}



int main()
{
	int T, I, J, K, N, n, m, cnt = 0, len;
	cin >> n;
	for (I = 0; I < n; I++)
		cin >> ar[I];

	Permutation(0, n);

	return 0;
}
/*
3
1 2 3
*/