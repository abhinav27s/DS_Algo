/*
Problem : Coin Change
Link : https://leetcode.com/problems/coin-change/
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        long long int dp[13][10001];
        int i,j;
        
        for(i=0;i<=coins.size();i++)
            dp[i][0] = 0;
        for(i=1;i<=amount;i++)
            dp[0][i] = INT_MAX;
        
        for(i=1;i<=coins.size();i++)
            for(j=1;j<=amount;j++){
                if(coins[i-1]<=j)
                    dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        if(dp[coins.size()][amount]>=INT_MAX)
            return -1;
        return dp[coins.size()][amount];
    }
};
/*
Approach : 2-D DP. Consider i->index of coins, j->sum/amount. 
Consider both cases- including and excluding current coin for coin change.
Fill matrix in Bottom up fashion.

Time: O(n*amount), Space: O(n*amount)
*/