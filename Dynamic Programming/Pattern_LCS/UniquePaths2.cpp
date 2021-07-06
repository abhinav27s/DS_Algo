/*
Problem : Unique Paths II
Link : https://leetcode.com/problems/unique-paths-ii/
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int dp[m][n];
        int i,j;
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)
            return 0;
        
        dp[0][0] = 1;
        for(i=1;i<m;i++){
            if(obstacleGrid[i][0]==1 || dp[i-1][0]==0)
                dp[i][0] = 0;
            else
                dp[i][0] = 1;
        }
        for(j=1;j<n;j++){
            if(obstacleGrid[0][j]==1 || dp[0][j-1]==0)
                dp[0][j] = 0;
            else
                dp[0][j] = 1;
        }
        
        for(i=1;i<m;i++)
            for(j=1;j<n;j++)
                if(obstacleGrid[i][j]==1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
            
        return dp[m-1][n-1];
    }
};
/*
Approach : dp[i][j] stores total no of ways to reach from top left(0,0) to bottom right(i,j). Consider base cases of - only one row or only one column in matrix. Then,
For cell having obstacle, dp[i][j] = 0;
A cell(i,j) can be reached only from 2 directions - (i,j-1) and (i-1,j) 
Total paths to cell(i,j)= sum of paths from both these options.
Time : O(n^2), Space : O(n^2) 
*/