/*
Remove Duplicates from Sorted Array
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1)
            return nums.size();
        int distinct = 0, i = 1;
        while (i < nums.size()) {
            if (nums[i] != nums[distinct]) {
                distinct++;
                nums[distinct] = nums[i];
            }
            i++;
        }
        return distinct + 1;
    }
};
/*
Approach - 2 pointer approach. Increment i till value is same as first pointer, else increment first pointer & 
update it with new value as i
*/