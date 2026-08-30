// 1248. Count Number of Nice Subarrays
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
        int ans = 0, size = nums.size(), count = 0, i = 0, oddCount = 0;
        for(int j = 0; j < size; j++)
        {
            if(nums[j]%2 == 1)
            {
                oddCount += 1;
                count = 0;
            }
            while(oddCount == k)
            {
                count++;
                if(nums[i]%2 == 1)
                    oddCount -= 1;
                i+=1;
            }
            ans += count;
        }
        return ans;
    }
};