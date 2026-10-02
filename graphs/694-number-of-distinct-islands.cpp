// 694. Number of Distinct Islands
// https://leetcode.com/problems/number-of-distinct-islands/
// Difficulty: Medium
// Topics: Array, Hash Table, Depth-First Search, Breadth-First Search, Union Find, Matrix
//
// You are given an m x n binary matrix grid. An island is a group of 1's
// (representing land) connected 4-directionally (horizontal or vertical.) You
// may assume all four edges of the grid are surrounded by water.
//
// An island is considered to be the same as another if and only if one island
// can be translated (and not rotated or reflected) to equal the other.
//
// Return the number of distinct islands.

class Solution {
private:
    unordered_map<string, int>mp;
    string temp = "";
public:
    void help(int r, int c, int m , int n, vector<vector<bool>>&visited, vector<vector<int>>&grid,  string prev)
    {
        if(r < 0 || c < 0 || r >= m || c >= n || visited[r][c] == true || grid[r][c] == 0)
        {
            return;
        }
        visited[r][c] = true;
        temp += prev;
        help(r+1, c, m, n, visited, grid, "D");
        help(r, c+1, m, n, visited, grid, "R");
        help(r-1, c, m, n, visited, grid, "U");
        help(r, c-1, m, n, visited, grid, "L");
        temp += "B";
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        
        for(int i=0; i<m;i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1 && visited[i][j] == false)
                {
                    temp = "";
                    help(i, j, m , n, visited, grid, "");
                    // cout << temp << endl;
                    mp[temp]++;
                }
            }
        }
        return mp.size();

    }
};