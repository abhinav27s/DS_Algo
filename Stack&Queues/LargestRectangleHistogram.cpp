/*
Problem: Largest Rectangle in Histogram
Link : https://leetcode.com/problems/largest-rectangle-in-histogram/
*/
class Solution {
    stack<int> st;
public:
    int largestRectangleArea(vector<int>& heights) {
        int i = 0, curArea, maxArea = 0, leftIndex, rightIndex, top;

        while (i < heights.size()) {
            if (st.empty() || heights[st.top()] <= heights[i]) {
                st.push(i);
                i++;
            }
            else {
                top = st.top();
                st.pop();
                rightIndex = i - 1, leftIndex;
                if (!st.empty())
                    leftIndex = st.top() + 1;
                else
                    leftIndex = 0;
                curArea = (rightIndex - leftIndex + 1) * heights[top];
                if (curArea > maxArea)
                    maxArea = curArea;
            }
        }

        if (!st.empty()) {
            rightIndex = st.top();
            while (!st.empty()) {
                top = st.top();
                st.pop();
                if (!st.empty())
                    leftIndex = st.top() + 1;
                else
                    leftIndex = 0;
                curArea = (rightIndex - leftIndex + 1) * heights[top];
                if (curArea > maxArea)
                    maxArea = curArea;
            }
        }
        return maxArea;
    }
};
/*
TCs
a. 1 2 3 4 5 => 5
b. 5 4 3 2 1 => 5
c. 3 4 5 1 2 => 9
d. 4 2 3 5 1 => 8
Approach : Push(index of elements, not values) onto stack until elements are greater than top of stack.
Once, element comes smaller, pop element and find just smaller in right side(which is current element i only) 
and just smaller element in left side(which is new top of stack or 0, if stack is empty). 
Calculate area with height as height of popped element and width from left to right smaller element. Update max area value.
*/