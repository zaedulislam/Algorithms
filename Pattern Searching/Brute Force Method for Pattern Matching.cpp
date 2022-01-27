// Brute Force Method for Pattern Matching.cpp
// Complexity: O(n * m)

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int SIZE = 1e6 + 5;
char text[SIZE];
char pattern[1000];


void BruteForceMatcher(int lenT, int lenP)
{
	int I, K, Index;
	for (I = 0; I < lenT; I++) {
		Index = I;
		for (K = 0; K < lenP && I + K < lenT; K++)
			if (text[I + K] != pattern[K]) break;

		if (K == lenP)
			printf("Match Found at Index %d.\n", Index);

	}

}

int main()
{
	int T, I, J, K, N, n, m, cnt = 0, lenT, lenP;

	printf("Enter Text: ");
	fgets(text, SIZE, stdin);
	lenT = strlen(text);

	if (text[lenT - 1] != '\0')
		text[lenT - 1] = '\0';
	lenT--;

	printf("Enter Pattern to Search: ");
	fgets(pattern, 1000, stdin);
	lenP = strlen(pattern);

	if (pattern[lenP - 1] != '\0')
		pattern[lenP - 1] = '\0';
	lenP--;

	BruteForceMatcher(lenT, lenP);

	return 0;
}
