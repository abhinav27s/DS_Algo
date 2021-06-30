/*
Problem : Palindrome Partitioning II
Link : https://leetcode.com/problems/palindrome-partitioning-ii/
*/

/*
Approach 1 : Similar to palindromic sequence, fill matrix bottom to up, left to right.
If substring(i,j) is a palindrome, store 0 as minCut.
Else, Check by partioning at each character of substring(i,j), minCuts of left part+right part is minimum or not.
Time : O(n^3), space : O(n^2)
*/
class Solution {
public:

    int minCut(string s) {
        int i,j,n=s.length();
        int dp[2001][2001]={n};
        for(i=n-1;i>=0;i--)
            for(j=i;j<n;j++){
                if(i==j)
                    dp[i][j] = 0;
                else if(s[i]==s[j] && dp[i+1][j-1]==0) // check if s(i,j) is palindrome or not
                    dp[i][j] = 0;
                else{
                    int min = n;
                    for(int k=i;k<j;k++) //check by partioning at each character of substring(i,j)
                        if(dp[i][k]+dp[k+1][j]<min)
                            min = dp[i][k]+dp[k+1][j];
                    dp[i][j] = 1 + min;
                }
            }
        return dp[0][n-1];
    }
};

/*
Approach 2 : O(n^2) is needed for an accepted submission. Here, a 1-DP matrix is sufficient as the left index i is fixed as 0, and we only need to check for
right index j, 0<=j<=n-1Also, to check if a substring is palindrome or not, we store this info in other matrix using dp approach, so as to get it in O(1) time,
when needed later to check.
So, 2 steps reqd. 
    i. build palindrome matrix
    ii. Build 1-D dp array to store minCut count
*/
class Solution {
public:
    int minCut(string s) {
        
        int i,j,n = s.length();
        
        //i. build palindrome matrix
        bool isPalindrome[2001][2001] = {false};
        for(i=n-1;i>=0;i--)
            for(j=i;j<n;j++){
                if(i==j)
                    isPalindrome[i][j] = true;
                else if(s[i]==s[j]){
                    if(j==i+1 || isPalindrome[i+1][j-1]==true)
                        isPalindrome[i][j] = true;
                }
                else
                    isPalindrome[i][j] = false;;
            }

        //ii. Build 1-D dp array to store minCut count
        int dp[2001];
        for(i=0;i<n;i++)
            dp[i] = n-1;
        dp[0] = 0;
        for(i=1;i<n;i++){
            if(isPalindrome[0][i]==true)
                dp[i] = 0;
            else{
                for(j=0;j<i;j++)
                    if(isPalindrome[j+1][i])
                        dp[i] = min(dp[i],1+dp[j]);
            }
        }
        
        return dp[n-1];
    }
};