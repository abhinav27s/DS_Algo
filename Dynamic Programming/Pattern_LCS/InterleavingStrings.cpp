/*
Problem : Interleaving String
Link : https://leetcode.com/problems/interleaving-string/
*/
class Solution {
    //Brute force approach using recursion & backtracking - O(n^n) - TLE on submission
    bool isInterleaveRecursive(string s1, string s2, string s3, int i, int j, int k){
        
        if(i==s1.length() && j==s2.length() && k==s3.length())
            return true;
        bool ans = false;
        if(i<s1.length() && k<s3.length() && s1[i]==s3[k])
            ans |= isInterleaveRecursive(s1,s2,s3,i+1,j,k+1);
        if(!ans && j<s2.length() && k<s3.length() && s2[j]==s3[k])
            ans |= isInterleaveRecursive(s1,s2,s3,i,j+1,k+1);
        
        return ans;
    }
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        //DP approach - O(mn)
        int m = s1.length(), n = s2.length();
        if(m+n!=s3.length())
            return false;
        
        bool dp[m+1][n+1];
        int i,j;
        dp[0][0] = true; // base case if both strings are empty
        
        //base cases if only one of the strings is empty
        for(i=1;i<=m;i++)
            if(s1[i-1]==s3[i-1])
                dp[i][0] = dp[i-1][0];
            else
                dp[i][0] = false;
        
        for(j=1;j<=n;j++)
            if(s2[j-1]==s3[j-1])
                dp[0][j] = dp[0][j-1];
            else
                dp[0][j] = false;
        
        // for all other cases 
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                if(s1[i-1]==s3[i+j-1] && s2[j-1]==s3[i+j-1])
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else if(s1[i-1]==s3[i+j-1])
                    dp[i][j] = dp[i-1][j];
                else if(s2[j-1]==s3[i+j-1])
                    dp[i][j] = dp[i][j-1];
                else
                    dp[i][j] = false;
            }
        }
        
        return dp[m][n];
        
    }
};
/*
Approach : First check that, length(s1)+length(s2) = length(s3)
1. Brute Force / backtracking : Simply, take each character of string s3 and compare, if it is equal to next character in s1 or s2. 
                                When end of all strings are reached, return true.
2. DP approach : Build a 2d matrix, where dp[i][j] means if substring s3(0,i+j) = interleaving of substring s1(0,i) & substring s2(0,j)
                Ref logmoj for more explanation.

TCs
1. s1="abc", s2="der", s3="adebcr" -> true 
2. s1 ="xxy", s2="xxz", s3="xxzxxy" -> true
3. s1 ="xxy", s2="xxz", s3="xxzxxxy" -> false
*/