/*
Problem: Maximum Length of Repeated Subarray
Link : https://leetcode.com/problems/maximum-length-of-repeated-subarray/
*/
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(),i,j;
        if(m==0 || n==0)
            return 0;
        int dp[1001][1001];
        //count will be zero if any of index is zero
        for(i=0;i<=m;i++)
            dp[i][0] = 0;
        for(i=0;i<=n;i++)
            dp[0][i] = 0;
        
        int maxLength = 0;
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++){
                if(nums1[i-1]==nums2[j-1]){ //if character matches
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if(dp[i][j]>maxLength)
                        maxLength = dp[i][j];
                }
                else
                    dp[i][j] = 0;
            }
        
        return maxLength;
    }
};
/*
Approach : 2-D DP. Index of both srings required. DP stored in a matrix. Check below cases 
            a. base cases- if any of the strings is empty
            b. If character matches, and if character does not match
*/