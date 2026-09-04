// 2285. Maximum Total Importance of Roads
// https://leetcode.com/problems/maximum-total-importance-of-roads/
// Difficulty: Medium
// Topics: Graph, Greedy, Sorting, Heap (Priority Queue)
//
// You are given an integer n denoting the number of cities in a country. The
// cities are numbered from 0 to n - 1.
// You are also given a 2D integer array roads where roads[i] = [ai, bi] denotes
// that there exists a bidirectional road connecting cities ai and bi.
// You need to assign each city with an integer value from 1 to n, where each
// value can only be used once. The importance of a road is then defined as the
// sum of the values of the two cities it connects.
// Return the maximum total importance of all roads possible after assigning the
// values optimally.

class Solution {
public:
    static bool help(pair<int, int>&a, pair<int, int>&b)
    {
        if(a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    }

    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        vector<int>inDegree(n ,0);
        for(int i = 0; i < roads.size(); i++)
        {
            inDegree[roads[i][1]]++;
            inDegree[roads[i][0]]++;
        }

        vector<pair<int, int>>temp;
        
        for(int i=0; i<n; i++)
        {
            temp.push_back({i, inDegree[i]});

        }

        sort(temp.begin(), temp.end(), help);
        
        vector<int>rank(n, 0);

        for(int i=0; i<n; i++)
        {
            rank[temp[i].first] = i + 1;
        }

        for(int i = 0; i < roads.size(); i++)
        {
            ans += rank[roads[i][0]] + rank[roads[i][1]];
        }
        return ans;
    }
};