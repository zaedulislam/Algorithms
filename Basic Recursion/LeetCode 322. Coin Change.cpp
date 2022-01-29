// LeetCode 322. Coin Change.cpp

#define CLR(ar) memset(ar, 0, sizeof(ar))
#define INTMAX 1000000

const int SIZE = 1e5 + 10;
int memo[SIZE], ar[SIZE], n;
bool status[SIZE];




int DP(int amount)
{
    if(amount < 0)
        return INTMAX;
    if(amount == 0)
        return 0;
    
    if(status[amount])
        return memo[amount];
    
    int I, ret = INTMAX;
    for(I = 0; I < n; I++)
        ret = min(ret, DP(amount - ar[I]) + 1);
    
    status[amount] = true;
    return memo[amount] = ret;
    
}



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        CLR(memo);
        CLR(status);
        
        int I;
        n = coins.size();
        for(I = 0; I < n; I++)
            ar[I] = coins[I];
        
        int ret =  DP(amount);
        if(ret == INTMAX)
            return -1;
        
        return ret;
    }
};
