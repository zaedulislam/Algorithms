// Combination Generator.cpp
// Complexity :
// NOTE: The below solution prints only distinct combinations even if there are duplicates in input.




#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define NL '\n'
const int SIZE = 100;
bool used[SIZE];
int ar[SIZE];
vector<int> number;




void Combination(int pos, int r, int n)
{
	int I;
	if (number.size() == r)
	{
		for (I = 0; I < r; I++)
			cout << number[I] << ' ';

		cout << NL;

		return;
	}


	for (I = pos; I < n; I++)
	{
		if (used[I] == false)
		{
			used[I] = true;
			number.push_back(ar[I]);
			Combination(I + 1, r, n);
			number.pop_back();
			used[I] = false;

		}

		/// For distinct combinations
		while (I + 1 < n && ar[I] == ar[I + 1])
			I++;

	}

}



int main()
{
	int I, n, r;

	cin >> n >> r;

	for (I = 0; I < n; I++)
		cin >> ar[I];

	//sort(ar, ar + n);

	//Combination(0, r, n);

	return 0;
}

/*
4 2
1 2 3 4
*/