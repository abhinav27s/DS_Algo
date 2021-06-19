/*
Problem : Edit Distane
Link : https://leetcode.com/problems/edit-distance/
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[501][501];
        int m=word1.length(), n=word2.length(),i,j;
        for(i=0;i<=m;i++)
            dp[i][0]=i;
        for(i=0;i<=n;i++)
            dp[0][i]=i;
        
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1+min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]);
            }
        return dp[m][n];
    }
};
/*
Approach : 2-D DP. Index of both strings required. DP stored in a matrix. Check below cases 
            a. base cases- if any of the strings is empty
            b. If character matches, and if character does not match
            Ref : Log moj 
*/