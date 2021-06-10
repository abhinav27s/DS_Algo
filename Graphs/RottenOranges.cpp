/*
Problem : Rotten Oranges
Link : https://leetcode.com/problems/rotting-oranges/
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(),i,j,flag;
        queue<pair<int,int>> que;
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                if(grid[i][j]==2)
                    que.push(make_pair(i,j));
        
        int time=0;
        while(!que.empty()){
            int size=que.size();
            flag=0;
            while(size>0){
                pair<int,int> ele = que.front();
                que.pop();
                int x=ele.first,y=ele.second;
                if(x-1>=0 && grid[x-1][y]==1){
                    grid[x-1][y]=2;
                    que.push(make_pair(x-1,y));
                    flag=1;
                }
                if(x+1<m && grid[x+1][y]==1){
                    grid[x+1][y]=2;
                    que.push(make_pair(x+1,y));
                    flag=1;
                }
                if(y-1>=0 && grid[x][y-1]==1){
                    grid[x][y-1]=2;
                    que.push(make_pair(x,y-1));
                    flag=1;
                }
                if(y+1<n && grid[x][y+1]==1){
                    grid[x][y+1]=2;
                    que.push(make_pair(x,y+1));
                    flag=1;
                }
                size--;
            }
            if(flag==1)
                time++;
        }
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                if(grid[i][j]==1)
                    return -1;
        
        return time;
    }
};
/*
Approach : BFS to find min time. At last, check if all oranges have become rotten or not.
*/