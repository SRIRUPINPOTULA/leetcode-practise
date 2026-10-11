// 3071. Minimum Operations to Write the Letter Y on a Grid
// https://leetcode.com/problems/minimum-operations-to-write-the-letter-y-on-a-grid/
// Difficulty: Medium
// Topics: Array, Matrix, Enumeration
//
// You are given a 0-indexed n x n grid where n is odd, and grid[r][c] is 0, 1,
// or 2.
//
// We say that a cell belongs to the Letter Y if it belongs to one of the
// following:
//   - The diagonal starting at the top-left cell and ending at the center cell
//     of the grid.
//   - The diagonal starting at the top-right cell and ending at the center cell
//     of the grid.
//   - The vertical line starting at the center cell and ending at the bottom
//     border of the grid.
//
// The Letter Y is written on the grid if and only if:
//   - All values at cells belonging to the Y are equal.
//   - All values at cells not belonging to the Y are equal.
//   - The values at cells belonging to the Y are different from the values at
//     cells not belonging to the Y.
//
// Return the minimum number of operations needed to write the letter Y on the
// grid given that in one operation you can change the value at any cell to 0,
// 1, or 2.

class Solution {
private:
    set<pair<int, int>>yNodes;
    int ans = INT_MAX;
public:
    void help(vector<vector<int>>& grid, int yValue, int diffValue)
    {
        int changes = 0;
        int mid = grid.size()/2;
        int n = grid.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                //ynodes
                if(yNodes.find({i, j}) != yNodes.end())
                {
                    if(grid[i][j] != yValue)
                        changes+=1;
                }
                //Not a yNode
                else
                {
                    if(grid[i][j] != diffValue)
                        changes+=1;
                }
            }
        }
       // cout << yValue << " " << diffValue <<  " " << changes << endl;
        ans = min(ans, changes);
    }

    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>values = {0, 1, 2};
        int i = 0, j = 0;
        while(i<n/2 && j <n/2)
        {
            yNodes.insert({i, j});
            i++;
            j++;
        }
        i = 0, j = n-1;
        while(i < n/2 && j > n/2)
        {
            yNodes.insert({i, j});
            i++;
            j--;
        }

        for(int i=n/2; i<n; i++)
        {
            yNodes.insert({i, n/2});
        }

        for(int a = 0; a<3; a++)
        {
            for(int b = 0; b < 3; b++)
            {
                if(a != b)
                {
                    help(grid, values[a], values[b]);
                }
            }
        }
        return ans;
    }
};