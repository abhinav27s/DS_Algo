/*
Problem: N-Queens
Link : https://leetcode.com/problems/n-queens/
*/
class Solution {
    bool isValid(vector<string> &board,int row, int col){
        int i,j,n=board.size();
        for(i=0;i<col;i++)
            if(board[row][i]=='Q')
                return false;
        i=row-1,j=col-1;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q')
                return false;
            i--;
            j--;
        }
        i=row+1,j=col-1;
        while(i<n && j>=0){
            if(board[i][j]=='Q')
                return false;
            i++;
            j--;
        }
        return true;
    }
    void NQueens(vector<string> &board, int colNo, vector<vector<string>> &result){
        int N = board.size();
        if(colNo==N){
            result.push_back(board);
            return;
        }
        for(int i=0;i<N;i++){
            board[i][colNo] = 'Q';
            if(isValid(board,i,colNo)==true)
                NQueens(board,colNo+1,result);
            board[i][colNo] = '.'; //backtrack to original
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        string temp;
        for(int i=0;i<n;i++){
            temp="";
            for(int j=0;j<n;j++)
                temp.push_back('.');
            board.push_back(temp);
        }
        vector<vector<string>> result;
        NQueens(board,0,result);
        
        return result;
    }
};
/*
Approach : Fill in column manner. 
For every column, check by placing queen in each row, till it reaches last column index (add result here).
*/
