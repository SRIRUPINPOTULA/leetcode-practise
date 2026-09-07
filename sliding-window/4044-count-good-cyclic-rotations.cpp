// 4044. Count Good Cyclic Rotations
// https://leetcode.com/problems/count-good-cyclic-rotations/
// Difficulty: Medium
// Topics: Array, Sliding Window, Prefix Sum
//
// You are given an integer array nums of even length n.
// A cyclic rotation of nums is obtained by choosing a prefix of nums whose
// length is between 0 and n - 1 (inclusive), and moving it to the end of the
// array while preserving the order of all elements.
// A cyclic rotation is good if the sum of its first n / 2 elements is strictly
// greater than the sum of its last n / 2 elements.
// Return the number of cyclic rotations of nums that are good.

class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int ans = 0;
        long long sum = 0;
        int size = nums.size();
        vector<long long>prefix(size, 0);
        
        for(int i=0; i<size; i++)
        {
            sum += nums[i];
            prefix[i] = sum;
        }

        int mid = size/2;
        
        for(int i=0; i<size; i++)
        {
            if(i == 0)
            {
                if(prefix[mid - 1] > sum - prefix[mid - 1])
                    ans++;
                continue;
            }
            
            int start = i;
            int end = start + mid - 1;
            if(end <= size-1)
            {
                long long oneHalf = prefix[end] - prefix[i-1];
                if(oneHalf > sum - oneHalf)
                    ans++;
            }
            else
            {
                int count = end - size;
                long long oneHalf = prefix[size-1] - prefix[i-1];
                oneHalf  = oneHalf + prefix[count];
                if(oneHalf > sum - oneHalf)
                    ans++;
            }
        }
        
        return ans;
    }
};