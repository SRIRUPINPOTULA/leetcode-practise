// 3737. Count Subarrays With Majority Element I
// https://leetcode.com/problems/count-subarrays-with-majority-element-i/
// Difficulty: Medium
// Topics: Array, Hash Table, Sliding Window, Counting
//
// You are given an integer array nums and an integer target.
//
// Return the number of subarrays of nums in which target is the majority
// element.
//
// The majority element of a subarray is the element that appears strictly more
// than half of the times in that subarray.

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;
        int size = nums.size();
        for(int i = 0; i < size; i++)
        {
            unordered_map<int, int>mp;
            for(int j = i; j < size; j++)
            {
                mp[nums[j]]++;
                if(mp.find(target) != mp.end())
                {
                    int len = j - i + 1;
                    if(mp[target] > len/2)
                        ans++;
                }
            }
        }
        return ans;
    }
};