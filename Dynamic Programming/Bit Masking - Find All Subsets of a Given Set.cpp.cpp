// Bit Masking - Find All Subsets of a Given Set.cpp

#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define NL '\n'

vector<int> vi;


int main()
{
	int tcases, I, J, K, N, n, m, cnt = 0, len;

	for(I = 1; I <= 10; I++)
		vi.push_back(I);

	int numOfSubsets = (1 << vi.size());

	for(I = 0; I < numOfSubsets; I++)
	{
		int pos = vi.size() - 1;
		int bitmask = I;

		cout << "{ ";
		while(bitmask > 0)
		{
			if((bitmask & 1) == 1)
				cout << vi[pos] << " ";

			bitmask = bitmask >> 1;
			pos--;
		}
		cout << "}\n";

	}

	return 0;
}



