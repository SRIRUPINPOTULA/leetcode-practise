// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/
// Difficulty: Medium
// Topics: Array, Binary Search, Sliding Window, Prefix Sum
//
// Given an array of positive integers nums and a positive integer target,
// return the minimal length of a subarray whose sum is greater than or equal to
// target. If there is no such subarray, return 0 instead.

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = INT_MIN;
        int slow = 0, fast = 0;
        int oneCount = 0, zeroCount = 0;
        int size = nums.size();
        while(fast < size)
        {
            if(nums[fast] == 0)
                zeroCount += 1;
            else
                oneCount += 1;
            if(zeroCount <= k)
            {
                ans = max(ans, fast - slow + 1);
            }
            else
            {
                while(slow < fast && zeroCount > k)
                {
                    if(nums[slow] == 0)
                    {
                        zeroCount--;
                    }
                    else
                    {
                        oneCount--;
                    }
                    slow+=1;
                }
            }
            fast += 1;
        }
        if(ans == INT_MIN)
            return 0;
        return ans;
    }
};