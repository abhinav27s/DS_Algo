/*
Problem : Combination Sum
Link : https://leetcode.com/problems/combination-sum/
*/
class Solution {
    void getCombinations(vector<int> nums, int index, int sum, vector<int> &temp, vector<vector<int>> &result){
        if(sum==0){
            result.push_back(temp);
            return;
        }
        if(index>=nums.size() || sum<0)
            return;
        
        //include the element, and make combinations
        temp.push_back(nums[index]);
        getCombinations(nums,index,sum-nums[index],temp,result);
        temp.pop_back();

        //exclude the element and make combinations
        getCombinations(nums,index+1,sum,temp,result);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        getCombinations(candidates,0,target,temp,result);
        
        return result;
    }
};
/*
Approach : Starting from 0 index, consider both cases to move forward - 
    i. Incude the element and make further combinations
    ii. Excude the element and make further combinations
    Time complexity : O(2^(n^2)) 
*/