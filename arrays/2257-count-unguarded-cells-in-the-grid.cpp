// 2257. Count Unguarded Cells in the Grid
// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/
// Difficulty: Medium
// Topics: Array, Matrix, Simulation
//
// You are given two integers m and n representing a 0-indexed m x n grid. You
// are also given two 2D integer arrays guards and walls where
// guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions
// of the ith guard and jth wall respectively.
// A guard can see every cell in the four cardinal directions (north, east,
// south, or west) starting from their position unless obstructed by a wall or
// another guard. A cell is guarded if there is at least one guard that can see
// it.
// Return the number of unoccupied cells that are not guarded.

class Solution {
public:
    void dfs(int r, int c, int m , int n, vector<vector<int>>&grid, vector<vector<bool>>&visited)
    {
        //left 
        for(int i=c-1; i>=0; i--)
        {
            if(visited[r][i] == true)
                break;
            if(grid[r][i] == 2 || grid[r][i] == 1)
                break;
            if(grid[r][i] == 0)
                visited[r][i] = true;
        }        

        //right
        for(int j=c+1; j < n; j++)
        {
            if(grid[r][j] == 2 || grid[r][j] == 1)
                break;
            if(grid[r][j] == 0)
                visited[r][j] = true;
        }

        //bottom
        for(int i=r+1; i<m; i++)
        {
            if(grid[i][c] == 2 || grid[i][c] == 1)
                break;
            if(grid[i][c] == 0)
                visited[i][c] = true;
        }

        //up
        for(int i=r-1; i>=0; i--)
        {
            if(grid[i][c] == 2 || grid[i][c] == 1)
                break;
            if(grid[i][c] == 0)
                visited[i][c] = true;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m, vector<int>(n, 0));
        for(int i=0; i<guards.size(); i++)
        {
            grid[guards[i][0]][guards[i][1]] = 1;
        }
        for(int i=0; i<walls.size(); i++)
        {
            grid[walls[i][0]][walls[i][1]] = 2;
        }
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                    dfs(i, j, m ,n, grid, visited);
            }
        }

        int ans = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 0 && visited[i][j] == false)
                    ans+=1;
            }
        }
        return ans;
    }
};