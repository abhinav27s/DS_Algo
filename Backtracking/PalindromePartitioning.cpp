/*
Problem: Palindrome Partitioning
Link : https://leetcode.com/problems/palindrome-partitioning/
*/
class Solution {
    bool checkPalindrome(string s,int a, int b){
        int i=a, j = b;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void palindromePartition(string s, int index, vector<string> &temp, vector<vector<string> > &result){
        if(index==s.length()){
            result.push_back(temp);
            return;
        }
        
        for(int i=index;i<s.length();i++)
            if(checkPalindrome(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                palindromePartition(s,i+1,temp,result);
                temp.pop_back();
            }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string> > result;
        palindromePartition(s,0,temp,result);
        return result;
    }
};
/*
Approach : From left to right, check by partitioning at each index if left substring is palindrome, recursively call for right substring.
Time: O(n^n)
*/