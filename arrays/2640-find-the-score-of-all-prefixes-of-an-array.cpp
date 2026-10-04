// 2640. Find the Score of All Prefixes of an Array
// https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/
// Difficulty: Medium
// Topics: Array, Prefix Sum
//
// We define the conversion array conver of an array arr as follows:
//   conver[i] = arr[i] + max(arr[0..i]) where max(arr[0..i]) is the maximum
//   value of arr[j] over 0 <= j <= i.
//
// We also define the score of an array arr as the sum of the values of the
// conversion array of arr.
//
// Given a 0-indexed integer array nums of length n, return an array ans of
// length n where ans[i] is the score of the prefix nums[0..i].

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int size = nums.size();
        vector<long long>res;
        int currMax = INT_MIN;
        long long currSum = 0;
        for(int i=0; i<size; i++)
        {
            currMax = max(currMax, nums[i]);
            long long sum = nums[i]+currMax;
            res.push_back(sum);
        }
        for(int i=1; i<size;i++)
        {
            res[i] += res[i-1];
        }
        return res;
    }
};