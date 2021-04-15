/*
Problem : Return true if Subarray with sum=0 exists
Link: https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1
*/
class Solution {
    unordered_map<int, bool> hashMap;
public:
    //O(n)
    bool subArrayExists(int arr[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum == 0)
                return true;
            if (hashMap.find(sum) != hashMap.end())
                return true;
            hashMap[sum] = true;
        }
        return false;
    }
};
/*
Approach : O(n) - Keep adding sum, and if sum is repeated or sum=0, return true
Similar to max contigous subarray sum.
*/