// 1557. Minimum Number of Vertices to Reach All Nodes

// Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.

// Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.

// Notice that you can return the vertices in any order.
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>res;
        vector<int>adj[n];
        vector<int>inDegree(n, -1);
        for(int i = 0; i < edges.size(); i++)
        {
            vector<int>temp = edges[i];
            adj[temp[0]].push_back(temp[1]);
            inDegree[temp[1]]++;
        }

        for(int i = 0; i<n; i++)
        {
            if(inDegree[i] == -1)
                res.push_back(i);
        } 

        return res;   
    }
};