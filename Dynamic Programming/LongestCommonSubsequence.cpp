/*
Problem : Longest Common Subsequence
Link : https://leetcode.com/problems/longest-common-subsequence/
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length(),i,j;
        int dp[1001][1001]; //stores LCS count
        
        //LCS = 0, if any of the strings is empty
        for(i=0;i<m;i++)
            dp[i][0] = 0;
        for(i=0;i<n;i++)
            dp[0][i] = 0;
        
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]) //if character matches
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }   
        
        return dp[m][n];
    }
};
/*
Approach : 2-D DP. Index of both srings required. DP stored in a matrix. Check below cases 
            a. base cases- if any of the strings is empty
            b. If character matches, and if character does not match
*/