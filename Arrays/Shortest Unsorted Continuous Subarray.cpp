/*
Problem : Shortest Unsorted Continuous Subarray
Link : https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
*/
class Solution {
public:
    // Time - O(n), space : O(1)
    int findUnsortedSubarray(vector<int>& nums) {
        int i,j,leftIndex,rightIndex,n=nums.size(),minm,maxm;
        
        i=1;
        while(i<n && nums[i]>=nums[i-1])
            i++;
        if(i==n) //if all array is sorted
            return 0;
        minm = nums[i];
        while(i<n){
            minm = min(minm,nums[i]);
            i++;
        }
        i=0;
        while(i<n){
            if(nums[i]>minm)
                break;
            i++;
        }
        leftIndex = i;
        
        j=n-2;
        while(j>=0 && nums[j]<=nums[j+1])
            j--;
        maxm = nums[j];
        while(j>=0){
            maxm = max(maxm,nums[j]);
            j--;
        }
        j=n-1;
        while(j>=0){
            if(nums[j]<maxm)
                break;
            j--;
        }
        rightIndex = j;
        if(rightIndex<leftIndex)
            return 0;
        return rightIndex-leftIndex+1;
        
    }
};
/*
Approach : Check multiple approaches discussed on :
https://leetcode.com/problems/shortest-unsorted-continuous-subarray/solution/
*/
