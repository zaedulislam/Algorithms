// HackerRank - Common Child.cpp

#include <bits/stdc++.h>
#define SET(ar) memset(ar, -1, sizeof(ar))
using namespace std;

const int SIZE = 5000 + 5;
string S1, S2;
int memo[SIZE][SIZE], len;




// Complete the commonChild function below.
int commonChild(int I, int J) {
    
    if(I == len || J == len)
        return 0;

    if(memo[I][J] != -1)
        return memo[I][J];

    int ret1 = 0, ret2 = 0, ret3 = 0;
    if(S1[I] == S2[J])
        ret1 = 1 + commonChild(I + 1, J + 1);
    else
    {
        ret2 = commonChild(I + 1, J);
        ret3 = commonChild(I, J + 1);
    }

    memo[I][J] = max(ret1, max(ret2, ret3));
    return memo[I][J];

}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    SET(memo);

    getline(cin, S1);
    getline(cin, S2);
    len = S1.length();
    
    int result = commonChild(0, 0);

    fout << result << "\n";

    fout.close();

    return 0;
}
