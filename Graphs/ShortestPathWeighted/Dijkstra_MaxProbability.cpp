/*
Problem : Path with Maximum Probability
Link : https://leetcode.com/problems/path-with-maximum-probability/
*/
class Solution {
    vector<double> maxPathDijkstra(vector<pair<int,double>> adjList[], int n, int source){
        
        priority_queue<pair<double,int>> maxHeap; // ordered by first element of pair, by default
        vector<bool> visited(n,false);
        vector<double> dist(n,0);
        
        dist[source]=1;
        maxHeap.push(make_pair(1,source));
        while(!maxHeap.empty()){

            int node = maxHeap.top().second;
            maxHeap.pop();
            visited[node]=true;

            for(int i=0;i<adjList[node].size();i++){
                int adjNode = adjList[node][i].first;
                double newDist = dist[node]*adjList[node][i].second;
                if(!visited[adjNode] && newDist>dist[adjNode]){
                    dist[adjNode] = newDist;
                    maxHeap.push(make_pair(newDist,adjNode));
                }
            }
        }

        return dist;
    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adjList[n]; 
        for(int i=0;i<edges.size();i++){
            adjList[edges[i][0]].push_back(make_pair(edges[i][1],succProb[i]));
            adjList[edges[i][1]].push_back(make_pair(edges[i][0],succProb[i]));
        }

        vector<double> dist = maxPathDijkstra(adjList,n,start);
        
        return dist[end];
    }
};
/*
Approach : Similar to network delay time, here, except that here, we find the longest path using Dijkstra.
*/