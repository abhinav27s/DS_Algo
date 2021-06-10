/*
Problem : All Paths From Source to Target
Link : https://leetcode.com/problems/all-paths-from-source-to-target/
*/
class Solution {
    void getAllPaths(vector<vector<int>> graph, int node, vector<int> &st, vector<vector<int>> &result){
        st.push_back(node);
        if(node==graph.size()-1)
            result.push_back(st);
        else{
            for(int i=0;i<graph[node].size();i++)
                getAllPaths(graph,graph[node][i],st,result);
        }
        st.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> st;
        vector<vector<int>> result;
        getAllPaths(graph,0,st,result);
        
        return result;
    }
};
/*
Approach : Simple backtracking in graph, to print all possible paths from node 0 to node n-1.
*/