// Longest Common Subsequence (LCS) [Bottom-Up Approach].cpp
// Complexity: O(n * m) where n = length of A and m = length of B.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

template < class T > inline T MAX(T a, T b) { return (a > b) ? a : b; }//NOTES:return max(

const int SIZE = 100;
char A[SIZE], B[SIZE];
int LCSLength, L[SIZE][SIZE];


void LCS(int lenA, int lenB)
{
	//L[lenA + 1][lenB + 1];
	int I, J;

	/*
	Following steps build L[lenA + 1][lenB + 1] in bottom up fashion. Note
	that L[I][J] contains length of LCS of A[0..I - 1] and B[0..J - 1]
	*/
	for (I = 0; I <= lenA; I++)
	{
		for (J = 0; J <= lenB; J++)
		{
			if (I == 0 || J == 0)
				L[I][J] = 0;
			else if (A[I - 1] == B[J - 1])
				L[I][J] = L[I - 1][J - 1] + 1;
			else
				L[I][J] = MAX(L[I - 1][J], L[I][J - 1]);
		}
	}

	/*
	L[lenA][lenB] contains length of LCS for A[0..lenA - 1] and B[0..lenB - 1]
	*/
	printf("The Length of the Longest Common Subsequence is: %d\n", L[lenA][lenB]);
	LCSLength = L[lenA][lenB];
}

void PrintLCS(int lenA, int lenB)
{
	int index = LCSLength, I, J;

	/*
	Create a character array to store the LCS string.
	*/
	char ans[index + 1];

	/*
	Set the terminating character. Otherwise while printing the LCS it may print some
	garbage values as we didn't tell the compile when to end.
	*/
	ans[index] = '\0';

	/*
	Start from the Right-most-Bottom-most Corner and One by One Store Characters in ans[].
	*/
	I = lenA, J = lenB;
	while (I > 0 && J > 0)
	{
		/*
		If current character in A[] and B[] are same, then current character is part of LCS.
		*/
		if (A[I - 1] == B[J - 1])
		{
			/*
			Put current character in ans.
			*/
			ans[index - 1] = A[I - 1];
			I--;
			J--;
			index--;
		}

		/*
		If not same, then find the larger of two and the direction of larger value.
		*/
		else if (L[I - 1][J] > L[I][J - 1])
			I--;
		else
			J--;
	}
	printf("The Longest Conmmon Subsequence is: %s\n", ans);
}

int main()
{
	int tcases, I, J, K, N, n, m, cnt = 0, lenA, lenB;
	scanf("%s%s", A, B);
	lenA = strlen(A);
	lenB = strlen(B);

	LCS(lenA, lenB);
	PrintLCS(lenA, lenB);

	return 0;
}
