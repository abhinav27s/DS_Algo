/*
Problem - Sort Colors
Link: https://leetcode.com/problems/sort-colors/
*/
class Solution {
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, i = 0;

        while (i <= right) {

            if (nums[i] == 0) {
                swap(nums, i, left);
                left++;
                i++; // ->To keep i >= left
            }
            else if (nums[i] == 2) {
                swap(nums, i, right);
                right--;
            }
            else
                i++;
        }


    }
};
/*
Approach: 3 pointer approach used.
Left pointer to swap & store 0s & move forward,
Right pointer - to swap & store 2s & move backward,
i pointer - to traverse from left to right
*/