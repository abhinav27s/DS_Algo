/*
Problem : Maximum Profit in Job Scheduling
Link : https://leetcode.com/problems/maximum-profit-in-job-scheduling/
*/
class Job{
    public:
    int start, end, profit;
    Job(int a,int b, int c){
        start = a;
        end = b;
        profit = c;
    }
};
bool comp(Job a, Job b){
    return ((a.end)<(b.end));
}
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
         vector<Job> jobs;
        for(int i=0;i<startTime.size();i++){
            Job obj(startTime[i], endTime[i], profit[i]);
            jobs.push_back(obj);
        }
        sort(jobs.begin(),jobs.end(),comp);

        int dp[50001];
        dp[0] = jobs[0].profit;
        
        for(int i=1;i<jobs.size();i++){
            dp[i] = max(jobs[i].profit,dp[i-1]);
            for(int j=i-1;j>=0;j--)
                if(jobs[j].end<=jobs[i].start){ // non-overlapping job 
                    dp[i] = max(dp[i],dp[j]+jobs[i].profit);
                    break;
                }
        }
        
        return dp[jobs.size()-1];
    }
};
/*
Approach : 1-D DP problem. Firstly sort the jobs based on end time. Then, store max profit possible(excluding current job and including it with other 
non -overlapping jobs,)  for every index in bottom up fashion.

Time : O(n^2), Space:O(n)
*/