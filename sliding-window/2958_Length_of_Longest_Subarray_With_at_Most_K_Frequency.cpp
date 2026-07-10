// 2958. Length of Longest Subarray With at Most K Frequency

// You are given an integer array nums and an integer k.

// The frequency of an element x is the number of times it occurs in an array.

// An array is called good if the frequency of each element in this array is less than or equal to k.

// Return the length of the longest good subarray of nums.

// A subarray is a contiguous non-empty sequence of elements within an array.
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int>mp;
        int left = 0;
        int right = 0;

        while(right < nums.size())
        {
            mp[nums[right]]++;
            if(mp[nums[right]] > k)
            {
                while(left < right )
                {
                    mp[nums[left]]--;
                    left += 1; 
                    if(mp[nums[right]] <= k)
                        break;
                    
                }         
            }
            else
            {
                ans = max(ans, right - left + 1);
            }
            right++;
        }

        return ans;
    }
};