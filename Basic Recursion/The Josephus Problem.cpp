/*
The Josephus Problem.cpp
Time Complexity: O(N) 
Problem Description: We Start with n people numbered 1 to n around a circle,  and we eliminate every
second remaining person until only one survives.
*/

#include <iostream>
#include <cstdio>
using namespace std;
#define NL '\n'


int Josephus(int N)
{
	if(N == 1)
		return 1;
	if(!(N & 1))
		return 2 * Josephus(N / 2) - 1;
	else
		return 2 * Josephus(N / 2) + 1;
}


int main()
{
	int T, I, J, K, N, n, m, k, cnt = 0, len;

	while(1)
	{
		cin >> N;

		if(N == 0)
			break;

		cout << Josephus(N) << NL;
	}


	return 0;
}




