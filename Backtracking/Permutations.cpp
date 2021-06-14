/*
Problem: Permutations (of string/number)
Link : https://leetcode.com/problems/permutations/
*/
class Solution {
    void swap(vector<int>& nums, int a, int b){
        int temp = nums[a];
        nums[a]=nums[b];
        nums[b] = temp;
    }
    void getAllPermutations(int index, vector<int>& nums, vector<vector<int>> &result){
        
        if(index==nums.size()-1)
            result.push_back(nums);
        for(int i=index;i<nums.size();i++){
            swap(nums,index,i);
            getAllPermutations(index+1,nums,result);
            swap(nums,index,i); //backtrack, to original position
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        getAllPermutations(0,nums,result);
        
        return result;
    }
};
/*
Approach : Simple backtracking, starting from 0.
Keep an index i, swap every index after i and use recursion for remaining.
*/