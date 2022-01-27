/* Word Wrap Problem (Greedy Solution).cpp
Given a sequence of words, and a limit on the number of characters that can be put in one line (line width). 
Put line breaks in the given sequence such that the lines are printed neatly. Assume that the length of each
word is smaller than the line width.

For example, consider the following string and line width M = 15
"Geeks for Geeks presents word wrap problem"

Following is the optimized arrangement of words in 3 lines
Geeks for Geeks
presents word
wrap problem
*/

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

vector<string> word;




void WordWrap(string S, int maxWidth)
{
    int I = 0, len = S.length(), SZ = word.size(), pos = 0;
    while(I < SZ)
    {
        if(pos + word[I].length() <= maxWidth)
        {
            cout << word[I];
            pos += word[I].length();
            I++;

            if(pos + 1 <= maxWidth)
            {
                cout << ' ';
                pos++;
            }

        }
        else
        {
            cout << '\n';
            pos = 0;
        }
    }

    cout << '\n';

}



int main()
{
    string S, w;
    int I, len, maxWidth;

    getline(cin, S);
    len = S.length();

    cin >> maxWidth;

    w = "";
    for(I = 0; I < len; I++)
    {
        if(S[I] == ' ')
        {
            word.push_back(w);
            w = "";
        }
        else
            w += S[I];
    }


    if(w.length() > 0)
        word.push_back(w);

    WordWrap(S, maxWidth);


	return 0;
}
