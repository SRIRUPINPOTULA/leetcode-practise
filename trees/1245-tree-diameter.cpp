// 1245. Tree Diameter
// https://leetcode.com/problems/tree-diameter/
// Difficulty: Medium
// Topics: Tree, Depth-First Search, Breadth-First Search, Graph
//
// The diameter of a tree is the number of edges in the longest path in that
// tree.
//
// There is an undirected tree of n nodes labeled from 0 to n - 1. You are
// given a 2D array edges where edges.length == n - 1 and edges[i] = [ai, bi]
// indicates that there is an undirected edge between nodes ai and bi in the
// tree.
//
// Return the diameter of the tree.

class Solution {
private:
    int res = 0;

public:
    int dfs(vector<int>adj[], int node, int parent)
    {
        int best1 = 0, best2 = 0;
        for(auto a : adj[node])
        {
            if(a == parent)
                continue;
            int dist = 1 + dfs(adj, a, node);
            if(best1 == 0)
            {
                best1 = dist;
            }
            else if(best1 != 0)
            {
                if(best1 < dist)
                {
                    best2 = best1;
                    best1 = dist;
                }
                else
                {
                    best2 = dist;
                }
            }
            res = max(res, best1+best2);
        }

        return best1;
    }

    int treeDiameter(vector<vector<int>>& edges) {
        int size = edges.size();
        vector<int>adj[size+1];
        for(int i=0; i<size; i++)
        {
            int a = edges[i][0], b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(adj, 0, -1);
        return res;
    }
};
