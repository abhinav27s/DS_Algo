/*
Problem :Best Time to Buy and Sell Stock - Can buy and sell only once
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/
class Solution {
public:
    int maxProfit(vector<int>& A) {
        int i, j, n = A.size(), max_profit = 0;

        i = 0;
        j = 1;
        while (i < n && j < n) {
            if (A[j] - A[i] > max_profit)
                max_profit = A[j] - A[i];
            if (A[j] - A[i] <= 0)
                i = j;
            j++;
        }

        return max_profit;
    }
};
/*
Approach: 2 pointer approach. O(n) similar to max contigous subarray sum.
One pointer to fix buying on day i. Increment second pointer j till profit>0 and keep track of max profit.
When profit<=0, check same from that element onwards  i.e. i=j
*/