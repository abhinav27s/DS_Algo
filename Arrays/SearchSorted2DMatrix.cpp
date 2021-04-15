/*
Problem: Search a 2D Matrix II -> all rows and cols are sorted
Link: https://leetcode.com/problems/search-a-2d-matrix-ii/
*/
class Solution {
public:
    // O(m+n)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int curRow = 0, curCol = matrix[0].size() - 1;
        while (curRow < matrix.size() && curCol >= 0) {
            if (matrix[curRow][curCol] == target)
                return true;
            if (matrix[curRow][curCol] < target)
                curRow++;
            else
                curCol--;
        }
        return false;
    }
};
/*
Compare top right element value with target and delete row or col one by one - O(m+n)
*/