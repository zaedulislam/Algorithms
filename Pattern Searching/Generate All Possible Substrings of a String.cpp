/*
Generate All Possible Substrings of a String.cpp
Complexity: O(n^3)
*/

#include<iostream>
#include<string>
using namespace std;

string S;




void GenerateAllSubstr()
{
    int I, J, K, len = S.length();

    /// Outermost loop picks the starting character
    for(I = 0; I < len; I++)
    {
        /// Mid loop considers all characters on right of the picked character as ending character of substring
        for(J = I; J < len; J++)
        {
            /// Innermost loop print the characters from current starting point to current end point
            for(K = I; K <= J; K++)
                cout << S[K];

            cout << endl;

        }
    }

    cout << endl;

}



void GenerateAllSubstrLenWise()
{
    int I, J, K, limit, len = S.length();

    /// Fix the substring's length
    for(I = 1; I <= len; I++)
    {
        /// Pick starting point
        for(J = 0; J <= len - I; J++)
        {
            /// Pick ending point
            limit = J + I - 1;
            for(K = J; K <= limit; K++)
                cout << S[K];

            cout << endl;
        }

    }

}



int main()
{
    cin >> S;
    GenerateAllSubstr();
    GenerateAllSubstrLenWise();
}

/*
Input:
abcd

Output:
a
ab
abc
abcd
b
bc
bcd
cd
d


a
b
c
d
ab
bc
cd
abc
bcd
abcd
*/