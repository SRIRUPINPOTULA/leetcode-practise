// 96. Unique Binary Search Trees
// https://leetcode.com/problems/unique-binary-search-trees/
// Difficulty: Medium
// Topics: Dynamic Programming, Tree, Binary Search Tree, Math, Catalan Number
//
// Given an integer n, return the number of structurally unique BST's (binary
// search trees) which has exactly n nodes of unique values from 1 to n.

class Solution {
private:
    vector<int>dp;
public: 
    int help(int m)
    {
        if( m == 0 || m == 1)
            return 1;
        if(dp[m] != 0)
            return dp[m];
        int total = 0;
        for(int i=1; i<=m; i++)
        {
            int left = help(i-1);
            int right = help(m - i);
            total += (left*right);
        }
        return dp[m] = total;
    }
    int numTrees(int n) {
        dp = vector<int>(n+1, 0);
        dp[0] = 1; dp[1] = 1;
        return help(n);
    }
};