/*
Problem : Stickler Thief
Link : https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1
*/
class Solution
{
    public:
    //Function to find maximum Sum of Non adjacent Elements
    int FindMaxSum(int arr[], int n)
    {
        int dp[n];
        dp[0] = arr[0];
        dp[1] = arr[1];
        dp[2] = arr[0]+arr[2];
        
        for(int i=3;i<n;i++)
            dp[i] = max(dp[i-2],dp[i-3])+arr[i];
        
        int max = 0;
        for(int i=0;i<n;i++)
            if(dp[i]>max)
                max = dp[i];

        return max;
    }
};
/*
Approach : Similar logic as Longest Increasing Subsequence, except that there is no need of second inner loop as per problem.
Similar implementation as Fibonacci Number 
Time - O(N), Space - O(N)
*/