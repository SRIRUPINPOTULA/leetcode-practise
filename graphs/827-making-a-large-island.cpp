// 827. Making A Large Island
// https://leetcode.com/problems/making-a-large-island/
// Difficulty: Hard
// Topics: Array, Depth-First Search, Breadth-First Search, Union Find, Matrix
//
// You are given an n x n binary matrix grid. You are allowed to change at most
// one 0 to be 1.
//
// Return the size of the largest island in grid after applying this operation.
//
// An island is a 4-directionally connected group of 1s.

class Solution {
private:
    map<pair<int, int>, int>mp;
    unordered_map<int, int>value;
public:
    void dfs(int r, int c, int n, vector<vector<bool>>&visited, vector<vector<int>>&grid, int &res, int id)
    {
        if(r < 0 || c < 0 || r >= n || c >= n || visited[r][c] == true || grid[r][c] == 0)
            return;
        res+=1;
        mp[{r, c}] = id;
        visited[r][c] = true;
        dfs(r+1, c, n, visited, grid, res, id);
        dfs(r-1, c, n, visited, grid, res, id);
        dfs(r, c+1, n, visited, grid, res, id);
        dfs(r, c-1, n, visited, grid, res, id);
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int ans = 0;
        int id = 0;
        vector<vector<bool>>visited(n, vector<bool>(n, false));
        for(int i = 0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1 && visited[i][j] == false)
                {
                    int res = 0;
                    dfs(i, j, n, visited, grid, res, id);
                    ans = max(ans, res);
                    value[id] = res;
                    id+=1;
                }
            }
        }

        vector<pair<int, int>>dirs = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};
        for(int i=0;i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 0)
                {
                    unordered_set<int>idColl;
                    int res = 1;
                    for(int a=0; a<4; a++)
                    {
                        int x = i + dirs[a].first;
                        int y = j + dirs[a].second;
                        if(mp.find({x, y}) != mp.end())
                        {
                            int id = mp[{x, y}];
                            if(idColl.find(id) == idColl.end())
                            {
                                res = res + value[id];
                                idColl.insert(id);
                            }
                        }
                    }
                    ans = max(ans, res);
                }
            }
        }

        return ans;
    }
};