/*
Problem : Longest Increasing Subsequence
Link : https://leetcode.com/problems/longest-increasing-subsequence/
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[nums.size()];
        dp[0] = 1;
        for(int i=1;i<nums.size();i++){
            dp[i] = 1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && dp[j]+1>dp[i])
                    dp[i] = dp[j]+1;
            }
        }
        
        int max = 0;
        for(int i=0;i<nums.size();i++)
            if(dp[i]>max)
                max = dp[i];
        
        return max;
    }
};
/*
Approach : 1-d DP problem. 
dp[i] stores the LIS length, including the ith element.
To consider the case of excluding ith element in final subset, we need to scan entire dp[] array and find the max at last. 

Time - O(n^2), Space - O(n)
*/