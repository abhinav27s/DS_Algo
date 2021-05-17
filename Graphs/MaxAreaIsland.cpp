/*
Problem: Max Area of Island
Link: https://leetcode.com/problems/max-area-of-island/
*/
class Solution {
    int DFS(int i, int j, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        return 1 + DFS(i - 1, j, grid) + DFS(i + 1, j, grid) + DFS(i, j - 1, grid) + DFS(i, j + 1, grid);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxArea = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    int area = DFS(i, j, grid);
                    if (area > maxArea)
                        maxArea = area;
                }

        return maxArea;
    }
};
/*
Approach: Simple DFS. Done without visited array . Make changes in grid itself.
*/