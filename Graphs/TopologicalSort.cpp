/*
Problem: Course Schedule II
Link: https://leetcode.com/problems/course-schedule-ii/
*/
int indegree[2001];
vector<int> result;
class Solution {
    void topoSortUtility(vector<int> adjList[], int node, int indegree[]) {
        result.push_back(node);
        for (int i = 0; i < adjList[node].size(); i++) {
            indegree[adjList[node][i]]--;
            if (indegree[adjList[node][i]] == 0)
                topoSortUtility(adjList, adjList[node][i], indegree);
        }
        indegree[node] = -1;
    }
    vector<int> topoSort(vector<int> adjList[], int indegree[], int n) {
        int i;
        for (i = 0; i < n; i++)
            if (indegree[i] == 0)
                topoSortUtility(adjList, i, indegree);

        if (result.size() < n)
            result.clear(); // return empty array, if cycle is present

        return result;

    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjList[numCourses]; // array of vectors is much faster
        int i, j;
        for (i = 0; i < numCourses; i++)
            indegree[i] = 0;
        result.clear();

        for (i = 0; i < prerequisites.size(); i++) {
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        return topoSort(adjList, indegree, numCourses);
    }
};
/*
Approach : Start  from node having indegree as 0. Visit it(make indegree as -1), and remove all its outgoing edges and update
indegrees of its adjacent nodes. Recursively using DFS, visit that adjacent nodes whose indegree have now become zero and repeat.
If no adjacent node has indegree 0, chose from remaiing nodes having indegree as 0.
Continue, till all nodes are visited (i.e.indegree =-1 for all nodes)
If there is cycle, at some point, there will be no node to chose with indegree as 0.
*/