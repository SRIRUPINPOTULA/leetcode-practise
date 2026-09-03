// 456. 132 Pattern
// https://leetcode.com/problems/132-pattern/
// Difficulty: Medium
// Topics: Array, Binary Search, Stack, Monotonic Stack, Ordered Set
//
// Given an array of n integers nums, a 132 pattern is a subsequence of three
// integers nums[i], nums[j] and nums[k] such that i < j < k and
// nums[i] < nums[k] < nums[j].
// Return true if there is a 132 pattern in nums, otherwise, return false.

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int size = nums.size();
        stack<int>st;
        int second = INT_MIN;
        for(int i=size-1; i>=0; i--)
        {
            if(nums[i] < second)
                return true;
            while(st.empty() != true && st.top() < nums[i])
            {
                second = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};