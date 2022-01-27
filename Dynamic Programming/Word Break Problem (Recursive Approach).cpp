/*
Word Break Problem (Recursive Approach).cpp

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be 
segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation. You may assume the dictionary 
does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: String can be segmented
Explanation: "leetcode" can be segmented as "leet code".

Complexity: O(2^n)
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string, int> MAP;




bool DictionaryContain(string s)
{
    if(MAP.find(s) != MAP.end())
        return true;

    return false;
}



bool WordBreak(string str)
{
    int I, len = str.length();

    if(len == 0)
        return true;

    for(I = 1; I <= len; I++)
    {
        if(DictionaryContain(str.substr(0, I)) && WordBreak(str.substr(I, len - I)))
            return true;
    }

    return false;
}



int main()
{
    string str;
    int n;
    
    cin >> n;
    for(int I = 0; I < n; I++)
    {
        cin >> str;
        MAP[str] = 1;
    }
    

    cin >> str;
    if (WordBreak(str))
        cout << "String can be segmented";
    else
        cout << "String can't be segmented";

	
    return 0;
}
