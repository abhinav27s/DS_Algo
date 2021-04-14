/*
Problem: Find majority element in O(n) time and O(1) space
Link: https://leetcode.com/problems/majority-element/submissions/
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i, majority, count;
        majority = nums[0];
        count = 1;

        for (i = 1; i < nums.size(); i++) {
            if (nums[i] == majority)
                count++;
            else
                count--;

            if (count == 0) {
                majority = nums[i];
                count = 1;
            }
        }
        return majority;
    }
};
/*
Approach :  Moore’s Voting Algorithm
Reference: https://www.geeksforgeeks.org/majority-element/
*/