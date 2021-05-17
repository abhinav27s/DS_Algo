/*
Problem : Number of Islands
Link : https://leetcode.com/problems/number-of-islands/
*/
class Solution {
    void DFS(int i, int j, vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        DFS(i - 1, j, grid);
        DFS(i + 1, j, grid);
        DFS(i, j - 1, grid);
        DFS(i, j + 1, grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1') {
                    count++;
                    DFS(i, j, grid);
                }

        return count;
    }
};
/*
Approach : Simple DFS. Done without visited array . Make changes in grid itself.
*/