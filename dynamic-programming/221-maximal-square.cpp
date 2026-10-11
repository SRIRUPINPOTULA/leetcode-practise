// 221. Maximal Square
// https://leetcode.com/problems/maximal-square/
// Difficulty: Medium
// Topics: Array, Dynamic Programming, Matrix
//
// Given an m x n binary matrix filled with 0's and 1's, find the largest
// square containing only 1's and return its area.

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int best = 0;
        vector<vector<int>>dp(m, vector<int>(n, 0));
        for(int r=0; r<m ;r++)
        {
            for(int c=0; c<n; c++)
            {
                if(matrix[r][c] == '1')
                {
                    if(r == 0 || c == 0)
                    {
                        dp[r][c] = 1;
                    }
                    else
                    {
                        dp[r][c] = 1+min(dp[r-1][c-1], min(dp[r-1][c], dp[r] [c-1]));

                    }
                }
                best = max(best, dp[r][c]);
            }
        }
        return best*best;

    }
};