/*
Problem : Sliding Window Maximum
Link : https://leetcode.com/problems/sliding-window-maximum/
*/
class Solution {
    deque<int> dq;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1)
            return nums;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            if (dq.empty() || nums[dq.back()] > nums[i])
                dq.push_back(i);
            else {
                while (!dq.empty() && nums[dq.back()] <= nums[i])
                    dq.pop_back();
                dq.push_back(i);
            }
            if (dq.front() < i - k + 1) // delete element out of current window 
                dq.pop_front();
            if (i >= k - 1) // print max for every index after k-1, as window slides from here
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};
/*
Approach : Using deque, push elements at back if these are lesser than queue'back element. 
If the element is greater, then firstly pop all lesser elements from queue, then push current element.
Also, pop elements from front, if they are out of current window slot.
*/