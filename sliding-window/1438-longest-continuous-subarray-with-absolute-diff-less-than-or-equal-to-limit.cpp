// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
// Difficulty: Medium
// Topics: Array, Queue, Sliding Window, Heap (Priority Queue), Ordered Set, Monotonic Queue
//
// Given an array of integers nums and an integer limit, return the size of the
// longest non-empty subarray such that the absolute difference between any two
// elements of this subarray is less than or equal to limit.

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        int size = nums.size();
        int left = 0;
        deque<int>maxd;
        deque<int>mind;
        for(int right = 0; right < size; right++)
        {
            while(maxd.empty() != true && maxd.back() < nums[right])
                maxd.pop_back();
            maxd.push_back(nums[right]);

            while(mind.empty() != true && mind.back() > nums[right])
                mind.pop_back();
            mind.push_back(nums[right]);

            while(maxd.front() - mind.front() > limit)
            {
                if(maxd.front() == nums[left]) 
                    maxd.pop_front();
                if(mind.front() == nums[left])
                    mind.pop_front();
                left++;
            }
            ans = max(ans, right - left + 1);       
        }

        return ans;
    }
};