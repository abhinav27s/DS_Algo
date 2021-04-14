/*
Problem: Best Time to Buy and Sell Stock II - can buy and sell any number of times, to maximise profit
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/
class Solution {
public:
    int maxProfit(vector<int>& A) {
        int i, j, n = A.size(), profit = 0;

        i = 0; j;
        while (i < n) {
            while (i < n - 1 && A[i + 1] < A[i])
                i++;
            if (i >= n - 1)
                return profit;
            j = i + 1;
            while (j < n && A[j] >= A[j - 1])
                j++;

            profit += (A[j - 1] - A[i]);  // i-> local minima , j--1 -> local maxima

            i = j;
        }
        return profit;
    }
};
/*
Approach: O(n). Find profit for all sets of local minima to local maxima .
Buy immediately(set i) as stock price starts to increase and increment j till price increases
 As stock price starts to decrease, sell immediately (stop j and add profit) and buy further only when prices start increasing.
*/