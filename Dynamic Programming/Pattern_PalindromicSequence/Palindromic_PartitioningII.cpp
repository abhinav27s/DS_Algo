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