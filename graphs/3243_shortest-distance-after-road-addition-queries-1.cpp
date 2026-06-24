// 3243. Shortest Distance After Road Addition Queries I

// You are given an integer n and a 2D integer array queries.

// There are n cities numbered from 0 to n - 1. Initially, there is a unidirectional road from city i to city i + 1 for all 0 <= i < n - 1.

// queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi. After each query, you need to find the length of the shortest path from city 0 to city n - 1.

// Return an array answer where for each i in the range [0, queries.length - 1], answer[i] is the length of the shortest path from city 0 to city n - 1 after processing the first i + 1 queries.

class Solution {
public:
    int help(vector<vector<int>>& adj, int n)
    {
        vector<int>dst(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

        pq.push({0, 0});
        dst[0] = 0;

        while(pq.empty() != true)
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(dst[node] < dist)
                continue;
            
            dst[node] = dist;

            for(auto a : adj[node])
            {
                if(dst[a] > 1 + dst[node])
                {
                    dst[a] = 1 + dst[node];
                    pq.push({dst[a], a});
                }
            }
        }

        return dst[n-1];
    }


    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>res(queries.size(), 0);
        vector<vector<int>>adj(n);
        
        for(int i=0; i<n-1; i++)
        {
            adj[i].push_back(i+1);
        }

        for(int i=0; i<queries.size(); i++)
        {
            vector<int>temp = queries[i];
            adj[temp[0]].push_back(temp[1]);
            res[i] = help(adj, n);
        }

        return res;
    }
};