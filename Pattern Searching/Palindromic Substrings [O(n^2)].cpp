/*
Palindromic Substrings [O(n^2)].cpp
Given a string, your task is to count how many palindromic substrings in this string.
The substrings with different start indexes or end indexes are counted as different substrings even they
consist of same characters.
Complexity: O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;




int CountPalindromicSubstr(string S)
{
    int center, len = S.length(), left, right, N = 2 * len - 1, cnt = 0;

    for(center = 0; center <= N; center++)
    {
        left = center / 2;
        right = left + center % 2;
        while(left >= 0 && right < len && S[left] == S[right])
        {
            cnt++;
            left--;
            right++;
        }
    }

    return cnt;
}



int main()
{
    string S;
    cin >> S;

    cout << CountPalindromicSubstr(S) << '\n';

	return 0;
}
