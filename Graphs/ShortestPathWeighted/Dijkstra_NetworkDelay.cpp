/*
Problem : Network Delay Time
Link: https://leetcode.com/problems/network-delay-time/
*/
typedef pair<int,int> pi;
class Solution {
    
    vector<int> minPathDijkstra(vector<pair<int,int>> adjList[], int n, int k){
        
        // i. initializing required data structures
        priority_queue<pi, vector<pi>, greater<pi> > minHeap; // ordered by first element of pair, by default
        vector<bool> visited(n+1,false);
        vector<int> dist(n+1,INT_MAX);
        
        dist[k]=0;
        minHeap.push(make_pair(0,k));
        
        while(!minHeap.empty()){
            int node = minHeap.top().second;
            minHeap.pop();
            visited[node]=true;
            for(int i=0;i<adjList[node].size();i++){
                int adjNode = adjList[node][i].first;
                int newDist = dist[node]+adjList[node][i].second;
                if(!visited[adjNode] && newDist<dist[adjNode]){
                    dist[adjNode] = newDist;
                    minHeap.push(make_pair(newDist,adjNode));
                }
            }
        }

        return dist;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // 1. Creating adjacency List
        vector<pair<int,int>> adjList[n+1];
        for(int i=0;i<times.size();i++)
            adjList[times[i][0]].push_back(make_pair(times[i][1],times[i][2]));
        
        //2. Finding shortest route from k to all nodes using Dijkstra's algorithm
        vector<int> dist = minPathDijkstra(adjList,n,k);
        
        //3. Finding maximum dist
        int maxDist=0;
        for(int i=1;i<=n;i++)
            if(dist[i]>maxDist)
                maxDist=dist[i];
        
        if(maxDist==INT_MAX)
            maxDist=-1;
        
        return maxDist;
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