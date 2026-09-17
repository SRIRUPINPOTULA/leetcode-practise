// 974. Subarray Sums Divisible by K
// https://leetcode.com/problems/subarray-sums-divisible-by-k/
// Difficulty: Medium
// Topics: Array, Hash Table, Prefix Sum
//
// Given an integer array nums and an integer k, return the number of non-empty
// subarrays that have a sum divisible by k.
// A subarray is a contiguous part of an array.

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int size = nums.size();
        int ans = 0;
        int prefixSum = 0;
        unordered_map<int, int>mp;
        mp[0] = 1;
        for(int i=0; i<size; i++)
        {
            prefixSum += nums[i];
            int remainder = ((prefixSum % k) + k) % k;
            if(mp.find(remainder) != mp.end())
            {   
                ans = ans + mp[remainder];
            }
            mp[remainder]++;
        }
        return ans;
    }
};