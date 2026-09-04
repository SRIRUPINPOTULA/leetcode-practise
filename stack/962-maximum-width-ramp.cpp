// 962. Maximum Width Ramp
// https://leetcode.com/problems/maximum-width-ramp/
// Difficulty: Medium
// Topics: Array, Stack, Monotonic Stack
//
// A ramp in an integer array nums is a pair (i, j) for which i < j and
// nums[i] <= nums[j]. The width of such a ramp is j - i.
// Given an integer array nums, return the maximum width of a ramp in nums. If
// there is no ramp in nums, return 0.

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int size =  nums.size();
        int ans = 0;
        stack<int>st;
        st.push(0);
        for(int i=1; i<size; i++)
        {
            if(nums[i] < nums[st.top()])
                st.push(i);
        }
        for(int j=size-1; j>=0; j--)
        {
            if(st.empty()== true)
                break;
            if(nums[st.top()] <= nums[j])
            {
                while(st.empty() != true && nums[st.top()] <= nums[j])
                {
                    ans = max(ans, j - st.top());
                    st.pop();
                }
            }
            else
                continue;
        }
        return ans;
    }
};