/*
Problem : Unbounded Knapsack Problem / Knapsack with Duplicate Items
Link : https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
*/
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       int dp[n+1][W+1]; 
       int i,j;
       for(i=0;i<=n;i++)
        dp[i][0] = 0;
       for(j=0;j<=W;j++)
        dp[0][j] = 0;
       for(i=1;i<=n;i++){
           for(j=1;j<=W;j++){
               dp[i][j] = dp[i-1][j]; //exclude current element
               if(j-wt[i-1]>=0)
                dp[i][j] = max(dp[i][j],val[i-1]+dp[i][j-wt[i-1]]); //include current element and get max of both, element can be taken again 
           }
       }
       
       return dp[n][W];
    }
};
/*
Approach : Fill in a 2d matrix, where i refers to number of elements, j refers to capacity of knapsack (from 0 to W)
Consider base cases, when i = 0, and when j = 0.
For rest, consider both cases - 
    a. excluding current element and finding profit for remaining, 
    b. including current element and finding profit

Time and space- O(n*W)
*/