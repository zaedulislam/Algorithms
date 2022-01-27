/*
Maximum Edge Removal from Tree to Make Even Forest.cpp
NOTES:
This problem is always solvable if the given graph has even nodes, impossible otherwise.
*/

#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define PB push_back

const int SIZE = 100 + 10;
bool visited[SIZE];
vector<int> G[SIZE];




int DFS(int u, int &res)
{
    visited[u] = true;

    int I, v, SZ = G[u].size(), currComponentNode = 0;
    for(I = 0; I < SZ; I++)
    {
        v = G[u][I];
        if(!visited[v])
        {
            int subtreeNodeCount = DFS(v, res);

            if(subtreeNodeCount & 1)
                currComponentNode += subtreeNodeCount;
            else
                res++;
        }

    }

    return (currComponentNode + 1);

}



int main()
{
	int T, I, J, K, N, n, m, k, cnt = 0, len, u, v;

    cin >> n >> m;

    for(I = 0; I < m; I++)
    {
        cin >> u >> v;
        G[u].PB(v);
        G[v].PB(u);
    }

    int res = 0;
    DFS(1, res);
    cout << res << NL;


    return 0;
}

/*
Problem Link:
1. http://codeforces.com/contest/982/problem/C
2. https://www.hackerrank.com/challenges/even-tree/problem

References:
1. https://www.geeksforgeeks.org/maximum-edge-removal-tree-make-even-forest/
2. https://www.geeksforgeeks.org/convert-tree-forest-even-nodes/
3. https://stackoverflow.com/questions/12043252/obtain-forest-out-of-tree-with-even-number-of-nodes
*/