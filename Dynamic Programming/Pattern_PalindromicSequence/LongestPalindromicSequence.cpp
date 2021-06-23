/*
Problem : Longest Palindromic Subsequence
Link : https://leetcode.com/problems/longest-palindromic-subsequence/
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int dp[1001][1001];
        for(int i=s.length()-1;i>=0;i--)
            for(int j=0;j<s.length();j++){
                if(j<i)
                    dp[i][j] = 0;
                else if(i==j)
                    dp[i][j] = 1;
                else{
                    if(s[i]==s[j])
                        dp[i][j] = 2+dp[i+1][j-1];
                    else
                        dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
                }
            }
        
        return dp[0][s.length()-1];
    }
};
/*
Approach 1(main) : 2-D DP. Since there is one string, so matrix with same string in row index(i) and column index(j) can be made as :
  a b c b c d            Eg - in string bbbab, (i,j) = (2,4) represents substring bab .
a 1        answer             dp[i][j] represents the count of longest palindromic string(i,j).
b 0 1                         Start filling the matrix from bottom left corner till we get top right corner as answer.
c 0 0 1                       For i>j, there is no valid string, so dp[i][j] = 0 always.
b 0 0 0 1                               And for i=j, dp[i][j] = 1, as single character is always a palindromic string. 
c 0 0 0 0 1
d 0 0 0 0 0 1

Approach 2(Alternative) : Given string s, take another string t = reverse(s). Longest common substring of both strings is the answer.
*/