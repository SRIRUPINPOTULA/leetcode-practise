// 1726. Tuple with Same Product
// https://leetcode.com/problems/tuple-with-same-product/
// Difficulty: Medium
// Topics: Array, Hash Table, Counting
//
// Given an array nums of distinct positive integers, return the number of
// tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are
// elements of nums, and a != b != c != d.

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
       //Approach 1
        int ans = 0;
        int size = nums.size();
        unordered_map<int, vector<pair<int, int>>>mp;
        unordered_map<int, set<pair<int, int>>>duplicate;
        
        for(int i = 0; i < size; i++)
        {
            for(int j = i+1; j < size; j++)
            {
                if(nums[i] == nums[j])
                    continue;
                else
                {
                    int pro = nums[i]*nums[j];
                    if(mp.find(pro) == mp.end())
                    {
                        mp[pro].push_back({nums[i], nums[j]});
                        duplicate[pro].insert({nums[i], nums[j]});
                    }
                    else
                    {
                        if(duplicate[pro].find({nums[i], nums[j]}) == duplicate[pro].end())
                        {
                            mp[pro].push_back({nums[i], nums[j]});
                            duplicate[pro].insert({nums[i], nums[j]});
                        }
                    }
                }
            }
        }

        for(auto a : mp)
        {
            int count = a.second.size();
            if(count > 1)
            {
                ans = ans + ((count) * (count-1)/2) * 8;
            }
        }

        //Approach - 2
        unordered_map<int, int>mp;
        for(int i=0; i < size; i++)
        {
            for(int j=i+1; j<size; j++)
            {
                int pro = nums[i] * nums[j];
                ans = ans + mp[pro]*8;
                mp[pro]++;
            }
        }
        return ans;
    }
};