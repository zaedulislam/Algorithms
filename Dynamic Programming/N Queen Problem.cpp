// N Queen Problem.cpp


#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
#define NL '\n'
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))


const int SIZE = 1e6;
int row[8 + 5];


bool IsPlace(int r, int c)
{
	int prev;
	for(prev = 1; prev < r; prev++)
	{
		if(row[prev] == c || (abs(prev - r) == abs(row[prev] - c)))
			return false;
	}
	return true;
}

void nQueen(int r, int N)
{
	int I, c;
	for(I = 1; I <= N; I++)
	{
		c = I;
		if(IsPlace(r, c))
		{
			row[r] = c;
			if(r == N)
			{
				cout << caseno << NL;
				caseno++;
			}
			else
				nQueen(r + 1, N);
		}
	}

}

int main()
{
	int tcases, I, J, K, N, n, m, cnt = 0, len;
	scanf("%d", &N);

	nQueen(1, N);


	return 0;
}
