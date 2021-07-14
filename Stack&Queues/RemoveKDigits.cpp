/*
Problem : Remove K Digits
Link : https://leetcode.com/problems/remove-k-digits/

Tc - 
k=3 in all 
1. 1432219 -> 1219
2. 1867678 -> 1667
3. 1003463 -> 33
4. 10023 -> 0
5. 44444 -> 444
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.length();
        if(k>=len)
            return "0";
        
        stack<char> st;
        st.push(num[0]);
        int i=1;
        while(i<len){
            if(num[i]>=st.top())
                st.push(num[i]);
            else{
                while(!st.empty() && st.top()>num[i]){
                    st.pop();
                    k--;
                    if(k==0)
                        break;
                }
                if(k==0)
                    break;
                st.push(num[i]);

            }
            i++;
        }
        while(i<len){
            st.push(num[i]);
            i++;
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        i=0;
        while(i<ans.length() && s[i]=='0')
            i++;
        ans=ans.substr(i);
        
        if(ans.size()==0)
            ans = "0";
        
        return ans;
    }
};
/*
Approach - Moving from left to right, if digits increase, push them onto stack.
If there is a decrease, then keep popping till top of stack comes greater.
Ensure to pop only k times, not more than that.
*/