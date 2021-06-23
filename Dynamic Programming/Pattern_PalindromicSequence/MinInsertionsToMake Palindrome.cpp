/*
Problem : Minimum Insertion Steps to Make a String Palindrome
Link : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
*/
class Solution {
public:
    int minInsertions(string s) {
        int dp[501][501];
        int n = s.length();
        for(int i=n-1;i>=0;i--)
            for(int j=0;j<n;j++){
                if(i>=j)
                    dp[i][j] = 0;
                else if(j-i==1){
                    if(s[i]==s[j])
                        dp[i][j] = 0;
                    else
                        dp[i][j] = 1;
                }
                else{
                    if(s[i]==s[j])
                        dp[i][j] = dp[i+1][j-1];
                    else
                        dp[i][j] = min(2+dp[i+1][j-1],min(1+dp[i+1][j],1+dp[i][j-1]));
                }
            }
        return dp[0][n-1];
    }
};
/*
Approach 1(main) : 2-D DP. Since there is one string, so matrix with same string in row index(i) and column index(j) can be made as :
  a b c b c d            Eg - in string bbbab, (i,j) = (2,4) represents substring bab .
a 1        ans                dp[i][j] represents the min char req. to be inserted to make string(i,j) as a palindrome.
b 0 1                         Start filling the matrix from bottom left corner till we get top right corner as answer.
c 0 0 1                       For i>j, there is no valid string, so dp[i][j] = 0 always.
b 0 0 0 1                               Consider case of single letter and double letter string as base cases here. 
c 0 0 0 0 1
d 0 0 0 0 0 1

*/