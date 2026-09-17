// 523. Continuous Subarray Sum
// https://leetcode.com/problems/continuous-subarray-sum/
// Difficulty: Medium
// Topics: Array, Hash Table, Math, Prefix Sum
//
// Given an integer array nums and an integer k, return true if nums has a good
// subarray or false otherwise.
// A good subarray is a subarray where:
//   - its length is at least two, and
//   - the sum of the elements of the subarray is a multiple of k.
//
// Note that:
//   - A subarray is a contiguous part of the array.
//   - An integer x is a multiple of k if there exists an integer n such that
//     x = n * k. 0 is always a multiple of k.

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefixSum = 0;
        int size = nums.size();
        if(size == 1)
            return false;
        unordered_map<int, int>mp;
        mp[0] = -1;
        for(int i=0; i<size; i++)
        {
            prefixSum += nums[i];
            int remainder = prefixSum % k;
            if(mp.find(remainder) != mp.end())
            {
                if(i - mp[remainder] >= 2)
                    return true;
            }
            else
                mp[remainder] = i;
        }
        return false;
    }
};