// Rolling Hash for Pattern Matching(Left to Right Approach).cpp

#include <bits/stdc++.h>

using namespace std;

#define SF scanf
#define PF printf
typedef long long LL; 	//NOTES:"%lld"

#define PRIME 999998727899999 		// (largest prime below 10^16)
#define PB push_back

const int SIZE = 1e6;
char str[SIZE], pattern[SIZE];
vector<LL> vi;


int main()
{
	int T, I, J, K, N, n, m, cnt = 0, len;

	LL hashno = 0, p = 57, p_pow = 1, mod = PRIME;
	for(I = 0; I < SIZE; I++)
	{
		vi.PB(p_pow);
		p_pow = ((p_pow % mod) * (p % mod)) % mod;
	}

	// n == length of the pattern
	while(SF("%d", &n) != EOF)
	{
		SF("%s", pattern);
		SF("%s", str);

		if(strlen(pattern) > strlen(str))
		{
			PF("\n");
			continue;
		}


		/// Calculate hash value for needle
        hashno = 0, p = 57, p_pow = 1, mod = PRIME;
        for(I = 0; I < n; I++)
		{
			hashno = ((hashno % mod) + ((pattern[I] - 'a' + 1) * vi[n - I - 1]) % mod) % mod;
		}

		LL h1 = hashno;


		/// Calculate hash value for haystack
        hashno = 0, p = 57, p_pow = 1, mod = PRIME;
        for(I = 0; I < n; I++)
		{
			hashno = ((hashno % mod) + ((str[I] - 'a' + 1) * vi[n - I - 1]) % mod) % mod;
		}

		if(h1 == hashno)
			PF("%d\n", 0);


		len = strlen(str);
		for(I = n; I < len; I++)
		{
			hashno = ((((hashno % mod) * vi[1]) % mod) - (((str[I - n] - 'a' + 1) * vi[n]) % mod) + mod) % mod;
			hashno = (hashno + ((str[I] - 'a' + 1) * vi[0]) % mod) % mod;

			if(hashno == h1)
				PF("%d\n", I - n + 1);

		}

		PF("\n");

	}


	return 0;
}



