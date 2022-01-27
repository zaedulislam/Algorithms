// Breadth First Search (No STL).cpp

#include <iostream>
using namespace std;
const int SIZE = 100;
int mat[SIZE][SIZE], parent[SIZE], level[SIZE], Q[SIZE], n, m, front = -1, rear = -1;
bool visited[SIZE];




void Enqueue(int value)
{
	if (rear == -1)
		front = 0;

	Q[++rear] = value;
}



void Dequeue()
{
	if (front > rear || front == -1)
	{
		cout << "Queue is empty!\n";
		return;
	}

	front++;
}



bool IsQueueEmpty()
{
	if (front > rear || front == -1)
		return true;
	
	return false;
}



void BFS(int src)
{
	//Q.push(src);
	Enqueue(src);

	visited[src] = true;
	parent[src] = 0;
	level[src] = 0;

	int I, u, v;
	while (!IsQueueEmpty())
	{
		u = Q[front];
		front++;

		cout << u << ' ';

		for (I = 1; I <= n; I++)
		{
			v = I;

			if (mat[u][v] == 1 && !visited[v])
			{
				visited[v] = true;
				parent[v] = u;
				level[v] = level[u] + 1;
				//Q.push(v);
				Enqueue(v);

			}
		}

	}

}



int main()
{
	int I, u, v;
	cin >> n >> m;
	for (I = 0; I < m; I++)
	{
		cin >> u >> v;
		mat[u][v] = 1;
		mat[v][u] = 1;
	}

	BFS(1);

	cout << endl;
	for (I = 1; I <= n; I++)
		cout << I << " = " << level[I] << endl;

	return 0;
}

/*
Input:
10 13
1 2
1 4
1 3
2 6
4 7
3 7
3 8
6 10
10 9
7 9
10 5
7 8
8 5

Output:
BFS Traversal: 1 2 3 4 6 7 8 10 9 5

*/