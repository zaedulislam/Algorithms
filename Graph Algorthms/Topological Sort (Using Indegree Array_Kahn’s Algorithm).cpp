// Topological Sort (Using Indegree Array_Kahn’s Algorithm).cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define SF scanf
#define PF printf
#define CLR(ar) memset(ar, 0, sizeof(ar))

const int SIZE = 1e5;
int indegree[SIZE];
vector<int> G[SIZE], topOrder;
queue<int> qi;




void KahnsAlgorithm(int N)
{
	while(!qi.empty())
		qi.pop();

    topOrder.clear();

	// Initialize Count of Visited Vertices.
	int I, u, v, countVisited = 0;

	// Enqueue All Vertices with In-degree 0.
    for(I = 0; I < N; I++)
	{
		if(indegree[I] == 0)
			qi.push(I);
	}

	// One by One Dequeue Vertices from Queue and Enqueue Adjacents if In-degree of Adjacent Becomes 0.
	while(!qi.empty())
	{
		// Extract front of Queue (or Perform Dequeue) and Add It to Topological Order.
		u = qi.front();
		countVisited++;

		qi.pop();
		topOrder.push_back(u);

		// Iterate through All Its Neighbouring Nodes of Dequeued Node u and Decrease Their In-degree by 1.
		for(I = 0; I < G[u].size(); I++)
		{
			v = G[u][I];
			indegree[v]--;

			if(indegree[v] == 0)
				qi.push(v);
		}

	}

	/* Check if there was a Cycle. If count of visited nodes is not equal to the number of nodes in the
	graph then the topological sort is not possible for the given graph. */
	if(countVisited != N)
	{
		PF("There exists a Cycle in the Graph\n");
		return;
	}

	// Print Topological Order.
	cout << "Topological Sort: ";
	for(I = 0; I < topOrder.size(); I++)
		PF("%d ", topOrder[I]);

	PF("\n");
}



int main()
{
	int tcases, I, J, K, n, m, cnt = 0, len, E, u, v, N;

	SF("%d", &tcases);

	while(tcases--)
	{
		SF("%d %d", &N, &E);

		CLR(indegree);

		for(I = 0; I <= N; I++)
			G[I].clear();

		for(I = 0; I < E; I++)
		{
			SF("%d%d", &u, &v);
			indegree[v]++;
			G[u].push_back(v);
		}

		KahnsAlgorithm(N);

	}

	return 0;
}

/*
Input:
1
6 6
5 2
5 0
4 0
4 1
2 3
3 1

Output:
Topological Sort: 4 5 2 0 3 1
*/
