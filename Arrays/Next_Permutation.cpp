/*
Problem : Next Permutation
Link: https://leetcode.com/problems/next-permutation/
*/
class Solution {
    void swap(vector<int>& nums, int x, int y) {
        int tmp = nums[x];
        nums[x] = nums[y];
        nums[y] = tmp;
    }
public:
    void nextPermutation(vector<int>& nums) {
        int i, j, n = nums.size();
        for (i = n - 2; i >= 0; i--)
            if (nums[i] < nums[i + 1])
                break;

        if (i == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int min_pos = i + 1;
        for (j = i + 2; j < n; j++)
            if (nums[j] > nums[i] && nums[j] < nums[min_pos])
                min_pos = j;

        swap(nums, i, min_pos);
        sort(nums.begin() + i + 1, nums.end());
    }
};
/*
Approach: Traverse from right to left and find break point where
ar[i]<ar[i-1]. If no such break point found, print reverse.
If found, swap it with its just next greater element and sort the remaining array frpm i+1 to n. 
O(n) time overall as the remaining array is almost sorted except one smallest element in middle that needs to be corrected.
*/