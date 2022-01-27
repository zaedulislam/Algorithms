
#include <iostream>
#include <cstdio>

#include <string>
#include <cstring>
#include <sstream>

#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>

#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iomanip>

//#define  LL long long
#define MAX 100005
#define MOD 1000000007

#define NL '\n'
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--) 
#define sf1(x) scanf("%d",&x)
#define sf scanf
#define pf1(x) printf("%d",x)
#define pf printf

using namespace std;

// BEGINTEMPLATE_BY_ZAYED
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int sz = 1e6;

typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long LL;//NOTES:"%lld"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

typedef stack<int> SI;
typedef queue <int> QI;
typedef vector <int> VI;
typedef pair <LL, LL> PLL;
typedef map <int, int> MII;
//typedef pair <int, int> PII;
typedef map <char, int> MCI;
typedef map <string, int> MSI;
typedef pair <string, int> PSI;
typedef map <string, string> MSS;

template<class T> inline void checkmin(T &a, T b){ if (b < a) a = b; }//NOTES:checkmin(
template<class T> inline void checkmax(T &a, T b){ if (b > a) a = b; }//NOTES:checkmax(
template<class T> inline T sqr(T x){ return x * x; }//NOTES:square
template<class T> inline T _max(T a, T b){ return (a > b) ? a : b; }
template<class T> inline T _min(T a, T b){ return (a < b) ? a : b; }
template<class T> inline T fAbs(T a) { return a< 0 ? a * (-1) : a; }
template<class T> inline void SWAP(T &a, T &b) { T t = a; a = b; b = t; }
LL _pow(LL base, LL power){
	LL I, res = base; if (power == 0) return 1;
	for (I = 0; I < power - 1; I++) res *= base;
	return res;
}
//Translator
bool isUpperCase(char c){ return c >= 'A' && c <= 'Z'; }//NOTES: isUpperCase(
bool isLowerCase(char c){ return c >= 'a' && c <= 'z'; }//NOTES: isLowerCase(
bool isVowel(char c) { return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'); }//NOTES: isVowel(
bool isLetter(char c){ return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }//NOTES: isLetter(
bool isDigit(char c){ return c >= '0' && c <= '9'; }//NOTES:isDigit(
char toLowerCase(char c){ return (isUpperCase(c)) ? (c + 32) : c; }//NOTES: toLowerCase(
char toUpperCase(char c){ return (isLowerCase(c)) ? (c - 32) : c; }//NOTES: toUpperCase(
int toInt(string s){ int r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:toInt(
double toDouble(string s){ double r = 0; istringstream sin(s); sin >> r; return r; }//NOTES:toDouble(
string toString(int n){ string s; stringstream convert; convert << n; s = convert.str(); return s; }//NOTES:toString
// ENDTEMPLATE_BY_ZAYED

 

#define INF (1<<20)
#define pii pair< int, int >
#define pb(x) push_back(x)
 
struct comp {
    bool operator() (const pii &a, const pii &b) 
    {
        return a.second > b.second;
    }
};
 
priority_queue< pii, vector< pii >, comp > Q;
vector< pii > G[MAX];
int D[MAX];
bool F[MAX];
 
int main() {
    int i, u, v, w, sz, nodes, edges, starting;
 
    // create graph
    scanf("%d %d", &nodes, &edges);
    for(i=0; i<edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        G[u].pb(pii(v, w));
        G[v].pb(pii(u, w)); // for undirected
    }
    scanf("%d", &starting);
 
    // initialize distance vector
    for(i=1; i<=nodes; i++) 
        D[i] = INF;
    D[starting] = 0;
    Q.push(pii(starting, 0));
 
    // dijkstra
    while(!Q.empty()) 
    {
        u = Q.top().first;
        Q.pop();
        if(F[u])
             continue;
        sz = G[u].size();
        for(i=0; i<sz; i++) 
        {
            v = G[u][i].first;
            w = G[u][i].second;
            if(!F[v] && D[u]+w < D[v]) 
            {
                D[v] = D[u] + w;
                Q.push(pii(v, D[v]));
            }
        }
        F[u] = 1; // done with u
    }
 
    // result
    for(i=1; i<=nodes; i++) 
            printf("Node %d, min weight = %d\n", i, D[i]);
    return 0;
}