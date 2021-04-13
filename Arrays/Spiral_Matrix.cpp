/*
Problem: Spiral Matrix
Link: https://leetcode.com/problems/spiral-matrix/
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row, col, M = matrix.size() - 1, N = matrix[0].size() - 1;
        int i, j;
        vector<int> result;
        row = 0; col = 0; 
        while (row <= M - row && col <= N - col) {
            //right
            for (j = col; j < N - col; j++)
                result.push_back(matrix[row][j]);

            //down
            for (i = row; i <= M - row; i++)
                result.push_back(matrix[i][N - col]);


            if (row == M - row)
                break;
            //left
            for (j = N - col - 1; j >= col; j--)
                result.push_back(matrix[M - row][j]);

            if (col == N - col)
                break;
            //up
            for (i = M - row - 1; i > row; i--)
                result.push_back(matrix[i][col]);

            row++;
            col++;
        }
        return result;
    }
};
/*
Approach : initialize left=0, right=N-1, top=0, bottom=M-1 and iterate over them in all 4 directions
In above code, this is taken :  left = col, right = N-col & top=row, bottom=M-row
*/