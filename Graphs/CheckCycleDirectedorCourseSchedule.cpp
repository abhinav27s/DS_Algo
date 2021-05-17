/*
Problem: Course Schedule
Link : https://leetcode.com/problems/course-schedule/
*/
class Solution {
    bool isCycle(int node, vector<int> adjList[], vector<bool>& visited, vector<bool>& rec) {
        if (visited[node] == true)
            return false;
        visited[node] = true;
        rec[node] = true;
        for (int i = 0; i < adjList[node].size(); i++) {

            if (!visited[adjList[node][i]]) {
                if (isCycle(adjList[node][i], adjList, visited, rec))
                    return true;
            }
            else if (rec[adjList[node][i]] == true)
                return true;
        }

        rec[node] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int> adjList[numCourses]; // array of vectors taking less time than vector of vectors
        vector<bool> visited(numCourses, false);
        vector<bool> rec(numCourses, false); // Recursion Stack to track back edge to already visited node
        int i;
        for (i = 0; i < pre.size(); i++)
            adjList[pre[i][0]].push_back(pre[i][1]);

        for (i = 0; i < numCourses; i++)
            if (isCycle(i, adjList, visited, rec))
                return false;

        return true;
    }
};
/*
Approach 1: DFS. Take 2 arrays - one for storing node in recursion stack and delete node(unvisit) after its work is over.
Cycle is present if there is any adjacent node that is already in recursion stack.
Other is visited array, which stores visited nodes and we don't unvisit for this array.
Time - O(E+V).
If we only take one visited array, them time complexity would be - O(V^2)

Approach 2: Find topological sort for the graph. If there is cycle, we cannot find topological sort and hence at some point,
there will be no node having indegree as 0.
*/