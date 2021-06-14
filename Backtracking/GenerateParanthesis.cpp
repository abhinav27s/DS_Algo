/*
Problem: Generate Parentheses
Link : https://leetcode.com/problems/generate-parentheses/
*/
class Solution {
    
    void getCombinations(string s, int left, int right, int n,vector<string> &result){
        if(right>left || left>n)
            return;
        if(left==right && left==n){
            result.push_back(s);
            return;
        }
        getCombinations(s+"(",left+1,right,n,result);
        getCombinations(s+")",left,right+1,n,result);
    }
public:
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string> result;
        getCombinations(s,0,0,n,result);
        
        return result;
    }
};
/*
Approach : Start with a null string first.
Append '(' first and make further strings using recursion.
Then append ')' and make further strings using recursion.
Stop if count(')')>count('(') or count('(')>n.
*/