/*
Problem: Diagonal Traverse
Link: https://leetcode.com/problems/diagonal-traverse/
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result, temp;
        int i, j, k, M = mat.size(), N = mat[0].size();
        int diagonal = 1;

        //diagonals originating from first row
        for (k = 0; k < N; k++) {
            i = 0;
            j = k;
            while (j >= 0 && i <= M - 1) {
                temp.push_back(mat[i][j]);
                i++;
                j--;
            }
            if (diagonal % 2 == 1)
                reverse(temp.begin(), temp.end());

            for (i = 0; i < temp.size(); i++)
                result.push_back(temp[i]);
            temp.clear();

            diagonal++;
        }

        //diagonals originating from last column
        for (k = 1; k < M; k++) {
            i = k;
            j = N - 1;
            while (j >= 0 && i <= M - 1) {
                temp.push_back(mat[i][j]);
                i++;
                j--;
            }
            if (diagonal % 2 == 1)
                reverse(temp.begin(), temp.end());

            for (i = 0; i < temp.size(); i++)
                result.push_back(temp[i]);
            temp.clear();

            diagonal++;
        }

        return result;
    }
};

/*
Approach : Store all diagonals from top to down and reverse odd no. diagonal alongside.
*/