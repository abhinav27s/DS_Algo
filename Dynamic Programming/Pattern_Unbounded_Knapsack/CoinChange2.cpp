/*
Problem : Coin Change II
Link : https://leetcode.com/problems/coin-change-2/
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[301][amount+1];
        int i,j;
        for(i=0;i<=coins.size();i++)
            dp[i][0] = 1;
        for(i=0;i<=amount;i++)
            dp[0][i] = 0;
        
        for(i=1;i<=coins.size();i++)
            for(j=1;j<=amount;j++){
                dp[i][j] = dp[i-1][j];
                if(j-coins[i-1]>=0)
                    dp[i][j]+=dp[i][j-coins[i-1]];
            }
        
        return dp[coins.size()][amount];
    }
};
/*
Approach : Similar to coin change.cpp
*/