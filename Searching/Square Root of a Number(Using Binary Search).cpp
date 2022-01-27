// Square Root of a Number(Using Binary Search).cpp

#include <bits/stdc++.h>
using namespace std;


double FindSqrt(double X)
{
	double first = 0, last = X, mid;
	while(last - first > .000000001)
	{
		mid = (first + last) / 2;

		if(mid * mid > X)
			last = mid;
		else
			first = mid;
	}

	cout << "X = " << mid * mid << endl;
	return mid;

}



int main()
{

	int T, I, J, K, N, n, m, k, cnt = 0, len;

	cout << FindSqrt(15) << endl;


	return 0;
}
