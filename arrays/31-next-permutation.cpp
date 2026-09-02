// 31. Next Permutation
// https://leetcode.com/problems/next-permutation/
// Difficulty: Medium
// Topics: Array, Two Pointers
//
// A permutation of an array of integers is an arrangement of its members into
// a sequence or linear order.
// The next permutation of an array of integers is the next lexicographically
// greater permutation of its integers. If such arrangement is not possible,
// the array must be rearranged as the lowest possible order (i.e., sorted in
// ascending order).
// Given an array of integers nums, find the next permutation of nums.
// The replacement must be in place and use only constant extra memory.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int index = size;
        for(int i=size-2; i>=0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                index=i;
                break;
            }
        }
        
        if(index == size)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        int minIndex = size-1;
        for(int i = size-1; i > index; i--)
        {
            if(nums[i] > nums[index])
            {
                minIndex = i;
                break;
            }   
        }

        swap(nums[index], nums[minIndex]);
        reverse(nums.begin() + index + 1, nums.end());
    }   
};