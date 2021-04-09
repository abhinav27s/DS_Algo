/*
Problem: Find Minimum in Rotated Sorted Array
Problem link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
*/
class Solution {
    int binarySearch(vector<int> nums) {
        int mid, n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            mid = (low + high) / 2;
            if (low == high) {
                if (mid == 0 || mid == n - 1)
                    return nums[mid];
                if (nums[mid - 1] > nums[mid] && nums[mid] <= nums[mid + 1])
                    return nums[mid];
            }
            else if (nums[mid] <= nums[high])
                high = mid;
            else if (nums[mid] > nums[high])
                low = mid + 1;
        }

        return nums[mid];
    }
public:
    int findMin(vector<int>& nums) {
        return binarySearch(nums);
    }
};
/*
Logic : Binary search used. Compare mid with high to chose one half and ignore other. When single element left, compare
with neighbour, considering corner indexes (0 & n-1 positions)
*/