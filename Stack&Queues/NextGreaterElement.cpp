/*
Problem : Next Greater Element II
Link : https://leetcode.com/problems/next-greater-element-ii/
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> result;
        int i, size = nums.size();
        for (i = 0; i < size - 1; i++)
            nums.push_back(nums[i]);

        result.push_back(-1);
        int lastGreater = -1;

        i = nums.size() - 2;
        while (i >= 0) {

            if (nums[i] < nums[i + 1]) {
                st.push(lastGreater);
                lastGreater = nums[i + 1];
                result.push_back(nums[i + 1]);
            }
            else if (nums[i] < lastGreater)
                result.push_back(lastGreater);
            else {
                lastGreater = -1;
                while (!st.empty()) {
                    int top = st.top();
                    st.pop();
                    if (top > nums[i]) {
                        lastGreater = top;
                        break;
                    }
                }
                result.push_back(lastGreater);
            }
            i--;
        }
        reverse(result.begin(), result.end());
        for (i = 0; i < size - 1; i++)
            result.pop_back();

        return result;
    }
};
/*
Above code approach : Firstly, append the given array with same array elements again. So, that rotated case can be taken care of.
Now, starting from rightmost element as -1, move towards left and for each element, its next greater element can be any of 4 cases- 
i. its previous element itself(if its greater), in that case, push next greater element of previous element into stack as it can be answer later
ii. next greater element of previous element (if its smaller)
iii. any of the elements stored in stack, which is greater than current
iv. -1 if stack also gets empty

At last, remove extra added array elements.
*/