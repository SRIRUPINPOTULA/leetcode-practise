// 611. Valid Triangle Number
// https://leetcode.com/problems/valid-triangle-number/
// Difficulty: Medium
// Topics: Array, Two Pointers, Binary Search, Sorting, Greedy
//
// Given an integer array nums, return the number of triplets chosen from the
// array that can make triangles if we take them as side lengths of a triangle.

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        int size = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<=size-3; i++)
        {
            for(int j=i+1; j<=size-2; j++)
            {
                int end = size-1;
                int low = j+1;
                while(low <= end)
                {
                    int mid = (low + end)/2;
                    if(nums[mid] < (nums[i] + nums[j]))
                    {
    
                        ans += (mid - low + 1);
                        low = mid + 1;
                    }
                    else if(nums[mid] >= (nums[i] + nums[j]))
                    {
                        end = mid-1;
                    }
                }
            }
        }

        return ans;
    }
};