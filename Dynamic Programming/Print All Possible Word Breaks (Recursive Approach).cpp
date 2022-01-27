/*
Print All Possible Word Breaks (Recursive Approach).cpp

Given a valid sentence without any spaces between the words and a dictionary of valid English words, find
all possible ways to break the sentence in individual dictionary words.

Example

Consider the following dictionary
{ i like sam sung samsung mobile ice cream icecream man go and mango }

Input: "ilikesamsungmobile"
Output: i like sam sung mobile
        i like samsung mobile

Input: "ilikeicecreamandmango"
Output: i like ice cream and man go
        i like ice cream and mango
        i like icecream and man go
        i like icecream and mango
*/

#include<iostream>
#include<map>
using namespace std;

map<string, int> MAP;




bool DictionaryContain(string str)
{
    if(MAP.find(str) != MAP.end())
        return true;

    return false;
}



void WordBreak(string str, string output)
{
    int I, len = str.length();

    if(len == 0)
    {
        if(output != "")
            cout << output << endl;

        return;
    }

    for(I = 1; I <= len; I++)
    {
        string prefix = str.substr(0, I);

        if(DictionaryContain(prefix))
            WordBreak(str.substr(I, len - I), output + prefix + " ");
    }

}



int main()
{
    int I, n;
    string str;

    cin >> n;
    for(I = 0; I < n; I++)
    {
        cin >> str;
        MAP[str] = 1;
    }

    cout << "Input: ";
    cin >> str;

    cout << "Output:\n";
    WordBreak(str, "");

    return 0;

}
