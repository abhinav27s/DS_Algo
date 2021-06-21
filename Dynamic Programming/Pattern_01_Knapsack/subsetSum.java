/*
Problem : Partition Equal Subset Sum
Link : https://leetcode.com/problems/partition-equal-subset-sum/ 
*/
class Solution {
    boolean subsetSum(int[] nums, int sum){
        boolean dp[][] = new boolean[nums.length+1][sum+1];
        int i,j;
        for(i=0;i<=nums.length;i++)
            dp[i][0] = true;

        for(i=1;i<=nums.length;i++)
            for(j=1;j<=sum;j++){
                if(dp[i-1][j]==true)
                    dp[i][j] = dp[i-1][j]; //exclude current element
                else if(j-nums[i-1]>=0)
                    dp[i][j] = dp[i-1][j-nums[i-1]]; //include current element
            }
        
        return dp[nums.length][sum];
    }
    public boolean canPartition(int[] nums) {
        int sum=0;
        for(int i=0;i<nums.length;i++)
            sum+=nums[i];
        if(sum%2!=0)
            return false;
        return subsetSum(nums,sum/2);
    }
}
/*
Approach : Based on 0/1 Knapsack dp pattern. 2 D matrix required i-> index of array & j-> sum. Build matrix.
Time : O(n*sum), Space :O(n*sum)
*/