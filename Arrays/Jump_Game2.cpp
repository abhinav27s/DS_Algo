/*
Problem : Jump Game II
Link: https://leetcode.com/problems/jump-game-ii/
*/
class Solution {
public:
    int jump(vector<int>& nums) { // O(n) time, O(1) space
        int a, b; // a stores current steps, b stores steps as backup if needed in future
        a = b = nums[0];
        int i = 0, n = nums.size(), jump;
        if (n == 0 || n == 1)
            return 0;
        jump = 1;
        while (i < n - 1) {
            if (nums[i] > b)
                b = nums[i];
            if (a == 0 && b == 0)
                return -1;
            if (a == 0) {
                a = b;
                jump++;
            }
            a--;
            b--;
            i++;
        }
        return jump;
    }
};
/*
Approach: traverse array, reducing current steps(a) and backup steps(b) & update b if it is lesser than current element.
If current steps are exhausted, it us where jump is needed.Increment jump. But don't directly jump to that max no.
Keep traversing linearly for next element too.
*/