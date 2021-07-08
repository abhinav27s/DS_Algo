/*
Problem : 2 Keys Keyboard
Link : https://leetcode.com/problems/2-keys-keyboard/ 
*/
class Solution {
public:
    int minSteps(int n) {
        int dp[n+1];
        dp[0]=dp[1]=0;
        
        for(int i=2;i<=n;i++){
            dp[i] = i;
            for(int x=2;x*x<=i;x++) //check only till sqrt(i) to save time
                if(i%x==0){ // then x and i/x both are factors of i
                    if(dp[i/x]+x < dp[i])
                        dp[i] = dp[i/x]+x;
                    else if(dp[x]+i/x < dp[i])
                        dp[i] = dp[x]+i/x ;
                }
        }
        return dp[n];
    }
};
/*
Approach : all factors of i need to be checked for min no. of operations.
One way is to check all factors from 2 to (i-1) - Overall time - O(n*n)
Other eficient way is to check only from 2 to sqrt(i) - Overall time - O(n*sqrt(n))
*/