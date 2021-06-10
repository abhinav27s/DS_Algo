/*
Problem : Word Search
Link : https://leetcode.com/problems/word-search/
*/
class Solution {
    bool ans;
    void findWord(vector<vector<char>> board, bool visited[][7],int i,int j,int index,string word){
        
        if(ans==true)
            return;
        if(index>=word.length()-1){
            ans=true;
            return;
        }
        int m=board.size(),n=board[0].size();
        
        visited[i][j]=true;
        if(i-1>=0 && !visited[i-1][j] && board[i-1][j]==word[index+1])
            findWord(board,visited,i-1,j,index+1,word);
        if(i+1<m && !visited[i+1][j] && board[i+1][j]==word[index+1])
            findWord(board,visited,i+1,j,index+1,word);
        if(j-1>=0 && !visited[i][j-1] && board[i][j-1]==word[index+1])
            findWord(board,visited,i,j-1,index+1,word);
        if(j+1<n && !visited[i][j+1] && board[i][j+1]==word[index+1])
            findWord(board,visited,i,j+1,index+1,word);
        
        visited[i][j]=false;
        
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int m=board.size(),n=board[0].size(),i,j;
        bool visited[7][7]={false};
        ans=false;
        
        int hashMapGrid[70]={0};
        int hashMapWord[70]={0};
        /* Check by hashing first */
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                hashMapGrid[board[i][j]-65]++;
         for(i=0;i<word.length();i++)
             hashMapWord[word[i]-65]++;
        
        for(i=0;i<70;i++)
            if(hashMapGrid[i]<hashMapWord[i])
                return false;
        
        /*If answer possible, only then apply DFS*/
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                if(board[i][j]==word[0]){
                    findWord(board,visited,i,j,0,word);
                    if(ans==true)
                        return true;
                }
        
        return false;
    }
};
/*
Approach : DFS for the character that matches the first letter of the word.
Optimazation : Before DFS, check by hash count, if the search query word has all the characters, sufficiently present in grid or not. If not, no need to have DFS.
*/