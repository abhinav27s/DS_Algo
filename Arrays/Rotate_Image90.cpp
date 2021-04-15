/*
Problem: Rotate Image by 90 degree clockwise using O(1) space
Link: https://leetcode.com/problems/rotate-image/
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i, j, k;
        int n = matrix.size();
        for (i = 0; i < n; i++) {
            vector<int> tmp = matrix[i];
            reverse(tmp.begin(), tmp.end());
            matrix[i] = tmp;
        }

        int counter = 0;
        while (counter < n) {
            j = 0; i = n - 1;
            while (1) {
                if (j == n - 1 - counter || i == counter)
                    break;
                int tmp = matrix[counter][j];
                matrix[counter][j] = matrix[i][n - 1 - counter];
                matrix[i][n - 1 - counter] = tmp;
                //swap(matrix[counter][j],matrix[i][counter]);
                j++;
                i--;
            }
            counter++;
            if (counter == n - 1)
                break;
        }
    }
};
/*
Approach: Reverse each row first. Then swap elements of 1st row and last column and so on.
*/