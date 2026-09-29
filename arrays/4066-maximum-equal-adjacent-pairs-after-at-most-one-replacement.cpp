// 4066. Maximum Equal Adjacent Pairs After at Most One Replacement
// https://leetcode.com/problems/maximum-equal-adjacent-pairs-after-at-most-one-replacement/
// Difficulty: Medium
// Topics: Array, Hash Table, Counting, Greedy
//
// You are given a 1-indexed integer array nums.
// You can choose two distinct values x and y and perform the following
// operation at most once:
//   Replace every occurrence of x in nums with y.
//
// Return the maximum possible number of pairs of adjacent elements that are
// equal after performing the operation.

class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int ans  = 0;
        int size = nums.size();
        int res = 0;
        map<pair<int, int>, int>mp;
        for(int i=0; i<nums.size(); i++)
        {
            if(i + 1 < size)
            {
                if(nums[i] == nums[i+1])
                    res++;
                mp[{nums[i], nums[i+1]}]++;
            }
           
        }

        ans = max(ans, res);
        
        for(auto a : mp)
        {
            int count = res;
            if(a.first.first != a.first.second)
            {
                if(mp.find({a.first.first, a.first.second}) != mp.end())
                    count += mp[{a.first.first, a.first.second}];
                if(mp.find({a.first.second, a.first.first}) != mp.end())
                    count += mp[{a.first.second, a.first.first}];
                ans = max(ans, count);
            }
        }
        
        return ans;
    }
};