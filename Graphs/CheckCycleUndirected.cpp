/*
Problem : Detect cycle in an undirected graph / Check if given graph is tree or not
Link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
Similar Link : https://www.geeksforgeeks.org/check-given-graph-tree/
*/
class Solution
{
    bool visited[100001];
public:

    bool hasCycle(vector<int>adj[], int index, int parent) {
        visited[index] = true;
        for (int i = 0; i < adj[index].size(); i++) {
            int neighbour = adj[index][i];
            if (visited[neighbour] && neighbour != parent)
                return true;
            if (!visited[neighbour] && hasCycle(adj, neighbour, index))
                return true;
        }

        return false;
    }
    //Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int>adj[])
    {
        int i;
        for (i = 0; i < V; i++)
            visited[i] = false;
        for (i = 0; i < V; i++) {
            if (!visited[i])
                if (hasCycle(adj, i, -1))
                    return true;
        }
        return false;
    }
};
/*
Approach: Using DFS, visit every node, and check if there is a back edge to an already visited node except the parent node.
Do, this for all nodes, till all nodes are visited
TIme Complexity : O(V+E), Space : O(V)
*/