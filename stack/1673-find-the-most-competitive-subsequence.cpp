// 1673. Find the Most Competitive Subsequence
// https://leetcode.com/problems/find-the-most-competitive-subsequence/
// Difficulty: Medium
// Topics: Array, Stack, Greedy, Monotonic Stack
//
// Given an integer array nums and a positive integer k, return the most
// competitive subsequence of nums of size k.
// An array's subsequence is a resulting sequence obtained by erasing some
// (possibly zero) elements from the array.
// We define that a subsequence a is more competitive than a subsequence b (of
// the same length) if in the first position where a and b differ, subsequence a
// has a number less than the corresponding number in b. For example, [1,3,4] is
// more competitive than [1,3,5] because the first position they differ is at
// the final number, and 4 is less than 5.

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int>res;
        int size = nums.size();
        
        stack<int>st;

        for(int i = 0; i<size; i++)
        {    
            while(st.empty() != true && st.top() > nums[i] && st.size() + (size - i) > k)
                st.pop();
            if(st.size() < k)
                st.push(nums[i]);
        }
        
        while(st.empty() != true)
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};