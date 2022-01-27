
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
#define NL '\n'

#define SET(ar) memset(ar, -1, sizeof(ar))
template < class T > inline T MIN(T a, T b) { return (a < b) ? a : b; } //NOTES:return min(


const int SIZE = 100;
int dp[SIZE][SIZE];
string S1, S2;

int EditDistance(int I, int J)
{
	if(I == 0)
		return J;

	if(J == 0)
		return I;

	if(dp[I][J] != -1)
		return dp[I][J];

	if(S1[I - 1] == S2[J - 1])
		return EditDistance(I - 1, J - 1);

	int Insert = 0, Remove = 0, Replace = 0;
	Insert = EditDistance(I, J - 1);
	Remove = EditDistance(I - 1, J);
	Replace = EditDistance(I - 1, J - 1);

	dp[I][J] = 1 + MIN(MIN(Insert, Remove), Replace);
	return dp[I][J];

}

int main()
{

	int tcases, I, J, K, N, n, m, cnt = 0, lenS1, lenS2;

	SET(dp);

	cin >> S1 >> S2;
	lenS1 = S1.length();
	lenS2 = S2.length();
	cout << EditDistance(lenS1, lenS2) << NL;

	return 0;
}
