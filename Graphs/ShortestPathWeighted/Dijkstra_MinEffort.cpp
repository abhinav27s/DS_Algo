/*
Problem : Path With Minimum Effort
Link : https://leetcode.com/problems/path-with-minimum-effort/
*/
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        
        vector<vector<int>> dist, visited;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > q; //minheap of dist,coordinates
        
        vector<int> tempDist,tempVisited;
        for(int i=0;i<row;i++){
            tempDist.clear();
            tempVisited.clear();
            for(int j=0;j<col;j++){
                tempDist.push_back(INT_MAX);
                tempVisited.push_back(0);
            }
            dist.push_back(tempDist);
            visited.push_back(tempVisited);
        }
        
        dist[0][0]=0;
        q.push(make_pair(0,make_pair(0,0)));
        
        while(!q.empty()){
            int frontDist = q.top().first;
            pair<int,int> frontPos = q.top().second;
            q.pop();
            int x = frontPos.first;
            int y = frontPos.second;
            visited[x][y]=1;
            if(y-1>=0)
                if(visited[x][y-1]==0 && max(frontDist,abs(heights[x][y]-heights[x][y-1]))<dist[x][y-1]){
                   dist[x][y-1] = max(frontDist,abs(heights[x][y]-heights[x][y-1]));
                    q.push(make_pair(dist[x][y-1],make_pair(x,y-1)));
                }
            if(y+1<col)
                if(visited[x][y+1]==0 && max(frontDist,abs(heights[x][y]-heights[x][y+1]))<dist[x][y+1]){
                   dist[x][y+1] = max(frontDist,abs(heights[x][y]-heights[x][y+1]));
                    q.push(make_pair(dist[x][y+1],make_pair(x,y+1)));
                }
            if(x-1>=0)
                if(visited[x-1][y]==0 && max(frontDist,abs(heights[x][y]-heights[x-1][y]))<dist[x-1][y]){
                   dist[x-1][y] = max(frontDist,abs(heights[x][y]-heights[x-1][y]));
                    q.push(make_pair(dist[x-1][y],make_pair(x-1,y)));
                }
            if(x+1<row)
                if(visited[x+1][y]==0 && max(frontDist,abs(heights[x][y]-heights[x+1][y]))<dist[x+1][y]){
                   dist[x+1][y] = max(frontDist,abs(heights[x][y]-heights[x+1][y]));
                    q.push(make_pair(dist[x+1][y],make_pair(x+1,y)));
                }
        }
        
        return dist[row-1][col-1];
    }
};
/*
Note: By default a max or min priority queue is created, ordered by first element of pair.

Single source shortest path (Dijkstra Algorithm)
1. Create a dist array for all nodes, marked with INT_MAX initially.
2. Visit the source node, set dist[source]=0, and insert pair(dist[source],source) to priority queue
3.  while(q is not empty){
		pop from queue // nearest node will be popped out automatically from priority queue
		update dist all those adjacent nodes from popped node, which are unvisited and lesser than current dist. Insert them in priority queue
	}
*/