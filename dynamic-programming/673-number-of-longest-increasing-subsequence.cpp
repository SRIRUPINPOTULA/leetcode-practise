// 673. Number of Longest Increasing Subsequence
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/
// Difficulty: Medium
// Topics: Array, Dynamic Programming, Segment Tree, Binary Indexed Tree
//
// Given an integer array nums, return the number of longest increasing
// subsequences.
//
// Notice that the sequence has to be strictly increasing.

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int size = nums.size();
        int maxLen = 1;
        vector<int>len(size, 1);
        vector<int>count(size, 1);
        for(int i=1; i<size; i++)
        {
            for(int j=i-1; j>=0; j--)
            {
                if(nums[j] < nums[i])
                {
                    if(len[i] < len[j]+1)
                    {
                        count[i] = count[j];
                        len[i] = 1+len[j];
                        maxLen = max(maxLen, len[j]+1);
                    }
                    else if(len[i] == len[j]+1)
                        count[i] += count[j];
                }
            }
        }
        int res = 0;
        for(int i = 0; i<size; i++)
        {
            if(len[i] == maxLen)
            {
                res += count[i];
            }
        }
        return res;
    }
};