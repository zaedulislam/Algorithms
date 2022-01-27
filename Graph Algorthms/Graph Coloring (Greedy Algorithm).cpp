/*
Graph Coloring (Greedy Algorithm).cpp

Time Complexity: O(V^2 + E) in worst case.
The below algorithm doesn’t always use minimum number of colors. Also, the number of colors used sometime 
depend on the order in which vertices are processed.
*/

#include<iostream>
#include<vector>
using namespace std;
const int SIZE = 1000 + 5;

vector<int> G[SIZE];
bool available[SIZE];
int color[SIZE];




void GraphColoring(int n)
{
    int I, c, u, v, SZ;
    color[0] = 0;

    for(I = 1; I < n; I++)
        color[I] = -1;

    for(I = 0; I < n; I++)
        available[I] = true;

    for(u = 1; u < n; u++)
    {
        SZ = G[u].size();
        for(I = 0; I < SZ; I++)
        {
            v = G[u][I];

            if(color[v] != -1)
                available[color[v]] = false;
        }


        for(c = 0; c < n; c++)
        {
            if(available[c] == true)
            {
                color[u] = c;
                break;
            }

        }

        for(I = 0; I < SZ; I++)
        {
            v = G[u][I];

            if(color[v] != -1)
                available[color[v]] = true;
        }

    }

}



int main()
{
    int I, n, m, u, v;

    cin >> n >> m;

    for(I = 0; I < m; I++)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    GraphColoring(n);

    for(I = 0; I < n; I++)
        cout << "Vertex " << I << " ---> " << color[I] << endl;

    return 0;
}

/*
Input:
5 6
0 1
0 2
1 2
1 3
2 3
3 4

5 6
0 1
0 2
1 2
1 4
2 4
4 3
*/
