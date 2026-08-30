// 1248. Count Number of Nice Subarrays
// https://leetcode.com/problems/count-number-of-nice-subarrays/
// https://leetcode.com/problems/count-number-of-nice-subarrays/
// Difficulty: Medium
// Topics: Array, Hash Table, Math, Sliding Window
//
// Given an array of integers nums and an integer k. A continuous subarray is
// called "nice" if there are exactly k odd numbers in it.
// Return the number of nice sub-arrays.

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int>mp;
        mp[0] = 1;
        int oddCount = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]%2 == 1)
                oddCount += 1;
            if(oddCount >= k)
            {
                if(mp.find(oddCount - k) != mp.end())
                {
                    ans += mp[oddCount - k];
                }
            }
            mp[oddCount]++;
        }
        return ans;
    }
};