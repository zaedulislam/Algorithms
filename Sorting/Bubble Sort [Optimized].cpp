// Bubble Sort [Optimized].cpp
#include<iostream>
using namespace std;
int compare = 0;
const int SIZE = 100;
int ar[SIZE];

template <class T> inline void SWAP(T &a, T &b) { T t = a; a = b; b = t;}

void bubbleSort(int n)
{
	int I, K, comparison = 0, cntSwap = 0,  shifted = 0;

	for(I = 0; I < n - 1; I++)
	{
		shifted = 0;
		for (K = 0; K < n - 1 - I; K++)    /// (n - 1 - I) -> As for each inner loop the biggest value will be in the
		{                                                          /// last of the array
			comparison++;          /// counts number of times comparison occurs
			if(ar[K] > ar[K + 1])       /// If the current element is bigger than the next
			{
			    SWAP(ar[K], ar[K + 1]);
				cntSwap++;
				shifted = 1;
			}
		}
		if (!shifted)
			break;
	}
	cout << "Comparison : " << comparison << "\n" << "Swap : " << cntSwap << endl;
}

int main()
{
	int tcases, I, J, K, N, n, m, cnt = 0, len;
    cin >> n;
    for(I = 0; I < n; I++)
        cin >> ar[I];

    bubbleSort(n);

    for(I = 0; I < n; I++)
        cout << ar[I] << " ";

	return 0;
}

/*
9
41 85 72 38 80 1 56 9 3
*/
