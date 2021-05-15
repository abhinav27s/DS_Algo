/*
Problem : Min Stack
Link : https://leetcode.com/problems/min-stack/
*/
class MinStack {
    stack<int> mainSt, minSt;
public:
    /** initialize your data structure here. */
    MinStack() {
        while (!mainSt.empty())
            mainSt.pop();
        while (!minSt.empty())
            minSt.pop();
    }

    void push(int val) {
        if (mainSt.empty() || val <= minSt.top())
            minSt.push(val);
        mainSt.push(val);
    }

    void pop() {
        if (minSt.top() == mainSt.top())
            minSt.pop();
        mainSt.pop();
    }

    int top() {
        return mainSt.top();
    }

    int getMin() {
        return minSt.top();
    }
};
/*
Approach : 2 stacks used in total. One is normal stack containing all elements.
Other is min stack containing only elements lesser or equal to the current top of min stack for finding minimum.
No need of pushing greater elements onto min stack.
*/