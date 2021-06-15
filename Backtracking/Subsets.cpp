/*
Problem : subsets
Link : https://leetcode.com/problems/subsets/
*/
//Approach 1 : Recursive / Backtracking : Consider both cases - include current element in subset, and exclude current element 
class Solution {
    void getAllSubsets(int index, vector<int> ar, vector<int> &temp,vector<vector<int>> &result){
        
        if(index>=ar.size())
            return;
        
        //include the current element in subset
        temp.push_back(ar[index]);
        result.push_back(temp); //print the subset
        getAllSubsets(index+1,ar,temp,result);
        temp.pop_back();
        
        //exclude the current element in subset
        getAllSubsets(index+1,ar,temp,result);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        result.push_back(temp); //insert empty subset
        getAllSubsets(0,nums,temp,result);
        
        return result;
    }
};
//Approach 2 : Iterative - Make all subsets corresponding to binary number representation of all numbers from 0 to 2^n
class Solution {
    vector<int> getSubsetFromNumber(int number, vector<int> ar){
        
        vector<int> subset;
        for(int i=0;i<ar.size();i++){
            //check if ith bit is set in the number or not
            if((1<<i & number)>0)
                subset.push_back(ar[i]);
        }
        return subset;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int maxSubset = pow(2,nums.size());
        for(int i=0;i<maxSubset;i++)
            result.push_back(getSubsetFromNumber(i,nums));
        
        return result;
    }
};
//Time complexity : O(2^(n^2)) 