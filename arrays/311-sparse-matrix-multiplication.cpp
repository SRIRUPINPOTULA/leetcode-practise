// 311. Sparse Matrix Multiplication
// https://leetcode.com/problems/sparse-matrix-multiplication/
// Difficulty: Medium
// Topics: Array, Hash Table, Matrix
//
// Given two sparse matrices mat1 of size m x k and mat2 of size k x n, return
// the result of mat1 x mat2. You may assume that multiplication is always
// possible.

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m1 = mat1.size();
        int k = mat1[0].size();
        int m2 = mat2[0].size();
        vector<vector<int>>res(m1, vector<int>(m2, 0));
        for(int x=0; x<m1; x++)
        {
            for(int y=0; y<m2; y++)
            {
                int value = 0;
                for(int z=0; z<k; z++)
                {
                    value = value + (mat1[x][z] * mat2[z][y]);
                }
                res[x][y] = value;
            }
        }
        return res;
    }
};