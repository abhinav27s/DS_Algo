/*
Problem : Jump Game
Link : https://leetcode.com/problems/jump-game/
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        bool dp[n];
        dp[0] = true;
        for(int i = 1;i<n;i++){
            dp[i] = false;
            for(int j=i-1;j>=0;j--)
                if(dp[j]==true && nums[j]>=i-j){
                    dp[i] = true;
                    break;
                }
        }
        
        return dp[n-1];
    }
};
/*
Approach : 1-D Approach Fibonnaci pattern. Time - O(N^2)
But it can be solved in O(N) using array logic approach
*/