// Longest Common Subsequence (LCS) [Top-Down Approach].cpp
// Complexity: O(n * m) where n = length of A and m = length of B.
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
using namespace std;
#define SF scanf
#define PF printf

template < class T > inline T MAX(T a, T b) { return (a > b) ? a : b; }//NOTES:return max(

const int SIZE = 100;

string ans;
char A[SIZE], B[SIZE];
int dp[SIZE][SIZE];
map<string, int> MAP;

int LCS(int I, int J)
{
	if(A[I] == '\0' || B[J] == '\0')
		return 0;

	if(dp[I][J] != -1)
		return dp[I][J];

	int ans = 0;
	if(A[I] == B[J])
		ans += 1 + LCS(I + 1, J + 1);
	else
	{
		int val1 = LCS(I, J + 1);
		int val2 = LCS(I + 1, J);
		ans = MAX(val1, val2);
	}

	dp[I][J] = ans;
	return dp[I][J];
}

void PrintLCS(int I, int J)
{
	if(A[I] == '\0' || B[J] == '\0')
	{
		cout << ans << endl;
		return;
	}
	if(A[I] == B[J])
	{
		ans += A[I];
		PrintLCS(I + 1, J + 1);
	}
	else
	{
		if(dp[I][J + 1] > dp[I + 1][J])
			PrintLCS(I, J + 1);
		else
			PrintLCS(I + 1, J);
	}
}

void PrintAllLCS(int I, int J)
{
	if(A[I] == '\0' || B[J] == '\0')
	{
		if(MAP[ans] == 0)
			MAP[ans] = 1;
		//cout << ans << endl;
		return;
	}
	if(A[I] == B[J])
	{
		ans += A[I];
		PrintAllLCS(I + 1, J + 1);
		ans.erase(ans.end() - 1);	// Delete last character.
	}
	else
	{
		if(dp[I][J + 1] > dp[I + 1][J])
			PrintAllLCS(I, J + 1);
		else if(dp[I][J + 1] < dp[I + 1][J])
			PrintAllLCS(I + 1, J);
		else
		{
			PrintAllLCS(I, J + 1);
			PrintAllLCS(I + 1, J);
		}
	}
}

int main()
{
	int tcases, I, J, K, N, n, m, cnt = 0, lenA, lenB;
	memset(dp, -1, sizeof(dp));

	SF("%s%s", A, B);
	lenA = strlen(A);
	lenB = strlen(B);
	PF("Length of LCS: %d\n", LCS(0, 0));

	ans = "";
	PrintLCS(0, 0);
	ans = "";
	PrintAllLCS(0, 0);

	map<string, int>::iterator it = MAP.begin();
	while(it != MAP.end())
	{
		cout << it -> first << endl;
		it++;
	}

	return 0;
}

