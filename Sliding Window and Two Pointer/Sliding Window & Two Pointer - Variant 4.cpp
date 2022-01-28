/*
Sliding Window/Two Pointers - Variant 4.cpp

Find the minimum of each possible sub-arrays with (static) size K. Example:
For array A = {0, 5, 5, 3, 10, 0, 4}, n = 7, and K = 3, there are n− K +1  = 7− 3 + 1 = 5
possible sub-arrays with size K = 3, i.e. {0, 5, 5}, {5, 5, 3}, {5, 3, 10}, {3, 10, 0}, and
{10, 0, 4}. The minimum of each sub-array is 0, 3, 3, 0, 0, respectively.
*/

#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define SF scanf
#define PF printf
#define PB push_back

const int SIZE = 1e6 + 10;
int ar[SIZE];
deque<int> DQ;




void FindMax(int n, int k)
{
    while(!DQ.empty())
        DQ.pop_front();

    int I;
    for(I = 0; I < k; I++)
    {
        while(!DQ.empty() && ar[DQ.back()] <= ar[I])
            DQ.pop_back();

        DQ.PB(I);
    }

    PF("%d", ar[DQ.front()]);

    for(I = k; I < n; I++)
    {
        while(!DQ.empty() && I - DQ.front() >= k)
            DQ.pop_front();

        while(!DQ.empty() && ar[DQ.back()] <= ar[I])
            DQ.pop_back();

        DQ.PB(I);

        PF(" %d", ar[DQ.front()]);

    }

    PF("\n");

}



void FindMin(int n, int k)
{
    while(!DQ.empty())
        DQ.pop_front();

    int I;
    for(I = 0; I < k; I++)
    {
        while(!DQ.empty() && ar[DQ.back()] >= ar[I])
            DQ.pop_back();

        DQ.PB(I);
    }

    PF("%d", ar[DQ.front()]);

    for(I = k; I < n; I++)
    {
        while(!DQ.empty() && I - DQ.front() >= k)
            DQ.pop_front();

        while(!DQ.empty() && ar[DQ.back()] >= ar[I])
            DQ.pop_back();

        DQ.PB(I);

        PF(" %d", ar[DQ.front()]);

    }

    PF("\n");

}



int main()
{
	int I, n, k;

    while(SF("%d%d", &n, &k) != EOF)
    {
        for(I = 0; I < n; I++)
            SF("%d", &ar[I]);

        FindMin(n, k);
        FindMax(n, k);

    }


	return 0;
}


