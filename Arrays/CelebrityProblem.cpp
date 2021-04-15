/*
Problem - The Celebrity Problem
Link : https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
*/
class Solution {
public:
    //O(n)
    int celebrity(vector<vector<int> >& M, int n) {
        deque<int> q;

        // considering all as celebrity initially
        for (int i = 0; i < n; i++)
            q.push_back(i);

        int i = 0, j = n - 1;

        // deleting people based on conditions - => runs for (n-1) times
        // if i knows j => i cannot be celebrity
        // if i does'nt know j=> j cannot be celebrity
        while (q.size() > 1) {
            if (M[i][j] == 0) {
                q.pop_back();
                j--;
            }
            else {
                i++;
                q.pop_front();
            }
        }

        // check for condition if there is no celebrity at all - 
        for (i = 0; i < n; i++)
            if (i != j && (M[q.front()][i] == 1 || M[i][q.front()] == 0))
                return -1;

        return q.front();
    }
};