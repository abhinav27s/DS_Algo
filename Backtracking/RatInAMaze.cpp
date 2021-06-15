/*
Problem : Rat in a Maze Problem - I 
Link : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
*/
class Solution{
    void getPaths(int i,int j,string s, vector<vector<int>> &matrix, int n ,vector<string> &result){
        
        if(i>=n || j>=n || i<0 || j<0)
            return;
        
        if(i==n-1 && j==n-1 ){
            result.push_back(s);
            return;
        }
        int tmp = matrix[i][j];
        matrix[i][j] = 2; //visit
        if(j+1 <n && matrix[i][j+1]==1)
         getPaths(i,j+1,s+"R",matrix,n,result);
        if(i+1 <n && matrix[i+1][j]==1)
         getPaths(i+1,j,s+"D",matrix,n,result);
        if(j-1 >=0 && matrix[i][j-1]==1)
         getPaths(i,j-1,s+"L",matrix,n,result);
        if(i-1 >=0 && matrix[i-1][j]==1)
         getPaths(i-1,j,s+"U",matrix,n,result);
         
        matrix[i][j] = tmp; //unvisit
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string s="";
        vector<string> result;
        if(m[0][0]==1)
            getPaths(0,0,s,m,n,result);
        sort(result.begin(),result.end());
        return result;
    }
};
/*
Approach : Simple DFS and backtracking, keeping track of visited cell in same path, and then unvisit later.
Time complexity : O(2^(n^2)) Space Complexity : O(n^2)
*/