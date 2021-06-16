/*
Problem : Sudoku Solver
Link : https://leetcode.com/problems/sudoku-solver/
*/
class Solution {
    bool isValid(vector<vector<char>> &board,int r, int c){
        char ch = board[r][c];
        for(int i=0;i<9;i++){
            if(board[r][i]==ch && i!=c)
                return false;
            if(board[i][c]==ch && i!=r)
                return false;
        }
        int xParent = r/3;
        xParent = xParent*3;
        int yParent = c/3;
        yParent = yParent*3;
        
        for(int i=xParent;i<xParent+3;i++)
            for(int j=yParent;j<yParent+3;j++)
                if(board[i][j]==ch && i!=r && j!=c)
                    return false;
        return true;
    }
    void fillCell(vector<vector<char>> &board, int i, int j,bool &found){
        if(found==true){
            return;
        }
        if(i==9){
            found = true;
            return;
        }
        if(j==9){
            fillCell(board,i+1,0,found);
            return;
        }
        if(board[i][j]!='.'){
            fillCell(board,i,j+1,found);
            return;
        }
        for(int x=1;x<=9;x++){
            string s = to_string(x);
            board[i][j] = s[0];
            if(isValid(board,i,j)==true)
                fillCell(board,i,j+1,found);
            if(found==true)
                return;
            board[i][j] = '.';
        }       
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool found = false;
        fillCell(board,0,0,found);
       
    }
};
/*
Approach : Simple backtracking. Start filling row wise and check for numbers from 1 to 9.
If a no. is valid, move to next cell, else try filling with next number possible.
Do until, we finish filling all cells.
*/