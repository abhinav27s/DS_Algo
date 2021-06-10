/*
Problem : Snakes and Ladders
Link : https://leetcode.com/problems/snakes-and-ladders/
*/
class Solution {
    int getMinSteps(vector<int> arr, int n){
        queue<pair<int, int>> q;
        vector<bool> visited(n*n+1,false);
        q.push(make_pair(1,0));
        visited[1]=true;
        
        while(!q.empty()){
            pair<int,int> front = q.front();
            q.pop();
            
            for(int i=1;i<=6;i++){
                int nextPos = front.first+i;
                if(nextPos==n*n) // important condition
                    return front.second+1;
                
                else if(nextPos<n*n && arr[nextPos]==-1 && !visited[nextPos]){
                    if(nextPos==n*n)
                        return front.second+1;
                    q.push(make_pair(nextPos,front.second+1));
                    visited[nextPos]=true;
                }
                else if(nextPos<n*n && arr[nextPos]>-1 && !visited[arr[nextPos]]){
                    if(arr[nextPos]==n*n) // important condition
                        return front.second+1;
                    q.push(make_pair(arr[nextPos],front.second+1));
                    visited[arr[nextPos]]=true;
                }
                
            }
        }
        return -1;
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        
        vector<int> positions;
        positions.push_back(0);
        int flag=1;
        for(int i=n-1;i>=0;i--){
            if(flag==1){
                for(int j=0;j<n;j++)
                    positions.push_back(board[i][j]);
                flag=0;
            }
            else if(flag==0){
                for(int j=n-1;j>=0;j--)
                    positions.push_back(board[i][j]);
                flag=1;
            }
        }
        for(int i=1;i<=n*n;i++)
            cout<<positions[i]<<" ";
        return getMinSteps(positions,n);
    }
};
/*
Approach : Convert given matrix to 1 d array first.
To find min steps, BFS is used. Be careful to not insert duplicate / already visited positions.
*/