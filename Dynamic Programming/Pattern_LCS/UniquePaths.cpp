/*
Problem : Unique Paths
Link : https://leetcode.com/problems/unique-paths/
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        int i,j;
        
        dp[0][0] = 1;
        for(i=1;i<=m;i++)
            dp[i][0] = 1;
        
        for(i=1;i<=n;i++)
            dp[0][i] = 1;
        
        for(i=1;i<m;i++)
            for(j=1;j<n;j++)
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            
        return dp[m-1][n-1];
        
    }
};
/*
Approach : dp[i][j] stores total no of ways to reach from top left(0,0) to bottom right(i,j). Consider base cases of - only one row or only one column in matrix. Then,
A cell(i,j) can be reached only from 2 directions - (i,j-1) and (i-1,j) 
Total paths to cell(i,j)= sum of paths from both these options.
Time : O(n^2), Space : O(n^2) 
*/