/*
Problem : Valid Parentheses
Link : https://leetcode.com/problems/valid-parentheses/
*/
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else {
                if (st.empty())
                    return false;
                if (st.top() == '(' && s[i] != ')')
                    return false;
                if (st.top() == '{' && s[i] != '}')
                    return false;
                if (st.top() == '[' && s[i] != ']')
                    return false;
                st.pop();
            }
        }
        if (st.empty())
            return true;
        return false;
    }
};
/*
Approach: Keep pushing on stack for '(', '{' & '['.
For ')', check stack and pop if '(' is at top. Similarly,for '}' & ']'.
Ensure that stack should be empty at last.
*/