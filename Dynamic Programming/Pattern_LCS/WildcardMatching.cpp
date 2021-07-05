/*
Problem - Wildcard Matching
Link - https://leetcode.com/problems/wildcard-matching/
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        bool dp[m+1][n+1];
        int i,j;
        
        dp[0][0] = true; // true if both string and pattern are empty
        for(i=1;i<=n;i++){ // base case - when string is empty 
            if(p[i-1]=='*')   
                dp[0][i] = dp[0][i-1]; // Example TC - s="", p="****" | O/p - true
            else
                dp[0][i] = false;
        }

        for(i=1;i<=m;i++) // base case - when pattern is empty 
            dp[i][0] = false;
        
        for(i = 1; i <= m; i++)
            for(j = 1 ;j <= n; j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*')
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                else
                    dp[i][j] = false;
            }
        return dp[m][n];
    }
};
/*
Approach : Similar to LCS. Take string as index i(row), and pattern as index j(column). dp[i][j] stores true if string(0,i) matches the pattern(0,j), else false.
First decide base conditions - 
    a. When string is empty (i=0)
    b. When pattern is empty (j=0)
Then make relation for cases when pattern character is - ?, *, or matches with string character.

Time - O(n^2), Space - O(n^2) 
*/