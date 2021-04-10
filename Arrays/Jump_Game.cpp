/*
Problem : Jump Game
Link: https://leetcode.com/problems/jump-game/
*/

class Solution {
public:
    bool canJump(vector<int>& nums) { //O(n) time, O(1) space
        int a, b; // a stores current steps, b stores steps as backup if needed in future
        a = b = nums[0];
        int i = 0, n = nums.size();
        while (i < n - 1) {
            if (nums[i] > b)
                b = nums[i];
            if (a == 0 && b == 0)
                return false;
            if (a == 0)
                a = b;
            a--;
            b--;
            i++;
        }
        return true;
    }
};
/*
Approach: traverse array, reducing current steps(a) and backup steps(b) & update b if it is lesser than current element 
*/