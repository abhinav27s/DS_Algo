/*
Problem : Steps by Knight
Link : https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1
*/
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    queue<pair<int,int>> q;
	    bool visited[N+1][N+1] = {false};
	    q.push(make_pair(KnightPos[0],KnightPos[1]));
	    visited[KnightPos[0]][KnightPos[1]] = true;
	    int moves=0;
	    
	    while(!q.empty()){
	        int width = q.size();
	        while(width>0){
	            pair<int,int> front = q.front();
	            int x = front.first,y=front.second;
	            if(x==TargetPos[0] && y==TargetPos[1])
	                return moves;
	            q.pop();
	            
	            if(x-1>=0 && y+2<=N && visited[x-1][y+2]==false){
	                q.push(make_pair(x-1,y+2));
	                visited[x-1][y+2] = true;
	            }
	            if(x+1<=N && y+2<=N && visited[x+1][y+2]==false){
	                q.push(make_pair(x+1,y+2));
	                visited[x+1][y+2] = true;
	            }
	            if(x-1>=0 && y-2>=0 && visited[x-1][y-2]==false){
	                q.push(make_pair(x-1,y-2));
	                visited[x-1][y-2] = true;
	            }
	            if(x+1<=N && y-2>=0 && visited[x+1][y-2]==false){
	                q.push(make_pair(x+1,y-2));
	                visited[x+1][y-2] = true;
	            }
	            
	            if(x-2>=0 && y-1>=0 && visited[x-2][y-1]==false){
	                q.push(make_pair(x-2,y-1));
	                visited[x-2][y-1] = true;
	            }
	            if(x-2>=0 && y+1<=N && visited[x-2][y+1]==false){
	                q.push(make_pair(x-2,y+1));
	                visited[x-2][y+1] = true;
	            }
	            if(x+2<=N && y-1>=0 && visited[x+2][y-1]==false){
	                q.push(make_pair(x+2,y-1));
	                visited[x+2][y-1] = true;
	            }
	            if(x+2<=N && y+1<=N && visited[x+2][y+1]==false){
	                q.push(make_pair(x+2,y+1));
	                visited[x+2][y+1] = true;
	            }
	            width--;
	        }
	        moves++;
	    }
	    return moves;
	}
};
/*
Approach : Simple BFS, with visited cell tracking
*/