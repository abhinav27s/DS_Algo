/*
Problem : Maximum of Absolute Value Expression
Link : https://leetcode.com/problems/maximum-of-absolute-value-expression/
*/
class Solution {
    // Returns max value of expression |A[i] - A[j]| + |i - j|
    int getMaxAbsoluteValue(vector<int> v){
        int i,n = v.size(),maxm,minm,ans;
        vector<int> sum(n);
        vector<int> diff(n);
        
        for(i=0;i<n;i++){
            sum[i] = v[i]+i;
            diff[i] = v[i]-i;
        }
        
        maxm=sum[0], minm=sum[0];
        for(i=1;i<n;i++){
            if(sum[i]>maxm)
                maxm = sum[i];
            if(sum[i]<minm)
                minm = sum[i];
        }
        ans = maxm-minm;
        
        maxm=diff[0], minm=diff[0];
        for(i=1;i<n;i++){
            if(diff[i]>maxm)
                maxm = diff[i];
            if(diff[i]<minm)
                minm = diff[i];
        }
        ans=max(ans,maxm-minm);
        return ans;
    }
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        vector<int> v1, v2;
        int n = arr1.size();
        for(int i=0;i<n;i++){
            v1.push_back(arr1[i]+arr2[i]);
            v2.push_back(arr1[i]-arr2[i]);
        }
        return max(getMaxAbsoluteValue(v1),getMaxAbsoluteValue(v2));
    }
};
/*
Approach : Superset of question to get max value of expression |A[i] - A[j]| + |i - j|. Here, just add and subtract corresponding values of both arrays to get one single array.
To get above max value, solve above single array expression and there are 4 outcomes : (A[i]+i)-(A[j]+j), (A[i]-i)-(A[j]-j), -(A[i]+i)+(A[j]+j), -(A[i]-i)+(A[j]-j)
Get max and min values for both exp1 -> A[i]+i and exp2 -> A[i]-i
And see whose difference is maximum
Time : O(N)
*/