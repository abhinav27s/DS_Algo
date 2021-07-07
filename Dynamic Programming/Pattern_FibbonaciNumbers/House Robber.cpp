/*
Problem : House Robber
Link : https://leetcode.com/problems/house-robber/
*/
class Solution {
public:
    int rob(vector<int>& arr) {
        int n = arr.size();
        int dp[n];
        dp[0] = arr[0];
        if(n>1)
            dp[1] = arr[1];
        if(n>2)
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