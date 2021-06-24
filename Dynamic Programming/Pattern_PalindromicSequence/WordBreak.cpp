/*
Problem : Word Break
Link : https://leetcode.com/problems/word-break/
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        int i,j,k; string temp;
        for(i=0;i<wordDict.size();i++)
            set.insert(wordDict[i]);
        
        bool dp[301][301]={false};
        for(i=s.length()-1;i>=0;i--)
            for(j=i;j<s.length();j++){
                if(i==j){
                    if(set.find(s.substr(i,1))!=set.end())
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                }
                else{
                    if(set.find(s.substr(i,j-i+1))!=set.end())
                        dp[i][j] = true;
                    else{
                        for(k=i;k<j;k++) //extra loop to make all possible left right combinations 
                            if(dp[i][k] && dp[k+1][j]){
                                dp[i][j] = true;
                                break;
                            }
                    } 
                }
            }
            
        return dp[0][s.length()-1];
        
    }
};
/*
Approach : Similar to longest palindromic sequence approach, 2 d matrix is built and filled from bottom to top.
One extra loop (k) is run to make all possible left-right combinations of the given string -> O(n)
Eg in "leetcode", possible left right combinations :("l","eetcode"),("le","etcode"), ("lee","tcode"), ("leet"."code") etc.
Overall Time complexity : O(n^3), Space : O(n^2)
*/