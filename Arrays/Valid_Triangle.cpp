/*
Problem : Valid Triangle Number
Link: https://leetcode.com/problems/valid-triangle-number/
*/

class Solution {
public:
    //O(n^2) time complexity
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i, j, k = 0, n = nums.size();
        int count = 0;
        for (i = 0; i < n - 2; i++) {
            k = 0;
            for (j = i + 1; j < n - 1; j++) { //O(n2)
                if (k <= j)
                    k = j + 1;
                // in other cases, k will resume from its last left position of previous j. So k traverses only once for a particular i value - O(n2)
                while (k<n && nums[i] + nums[j]>nums[k])
                    k++;
                count += k - j - 1;
            }
        }
        return count;
    }
};

/*
Approach : Sort array. Use 3 pointers such that j and k travels once once for every i. - O(n2) time
*/