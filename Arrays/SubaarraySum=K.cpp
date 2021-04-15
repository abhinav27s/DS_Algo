/*
Problem : Subarray Sum Equals K  || // TC: -2,4,-2,2, k=2 || 0,0,0 k=0 
Link: https://leetcode.com/problems/subarray-sum-equals-k/
*/
class Solution {
    unordered_map<int, int> hashMap;
public:
    int subarraySum(vector<int>& arr, int k) {
        int sum = 0, count = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (sum - k == 0) 
                count++;
            if (hashMap.find(sum - k) != hashMap.end()) 
                count += hashMap[sum - k];

            if (hashMap.find(sum) == hashMap.end())
                hashMap[sum] = 1;
            else
                hashMap[sum]++;

        }
        return count;
    }
};
/*
Approach: Similar to Subarray Sum = 0 problem.
Keep adding sum, and if sum-k=0, use that subarray(increment count) and also If sum-k is repeated, use that subarray (add its count)
Also, update current sum count in hash map, so that it can be used for making later subarrays.
*/