/*
Problem : Unique Paths
Link : https://leetcode.com/problems/unique-paths/
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1];
        int i,j;
        
        dp[0][0] = 0;
        for(i=1;i<=m;i++){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        for(i=1;i<=n;i++){
            dp[0][i] = 0;
            dp[1][i] = 1;
        }
        
        for(i=2;i<=m;i++)
            for(j=2;j<=n;j++)
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            
        return dp[m][n];
        
    }
};
/*
Approach : dp[i][j] stores total no of ways to reach from top left to bottom right. Consider base cases of - only one row or only one column in matrix. Then,
From a cell(i,j), there are only 2 options to move - 
    a. 1 cell right - i.e. matrix with 1 column lesser and same no. of rows -> dp[i][j-1]
    b. 1 cell down - i.e. matrix with 1 row lesser and same no. of cols -> dp[i-1][j] 
Total paths from cell(i,j)= sum of paths of both these options.
Time : O(n^2), Space : O(n^2) 
*/