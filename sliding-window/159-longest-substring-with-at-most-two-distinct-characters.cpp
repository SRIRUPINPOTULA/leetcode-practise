// 159. Longest Substring with At Most Two Distinct Characters
// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
// Difficulty: Medium
// Topics: Hash Table, String, Sliding Window
//
// Given a string s, return the length of the longest substring that contains at
// most two distinct characters.

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int ans = INT_MIN;
        unordered_map<char, int>mp;
        int first = 0;
        for(int second = 0; second < s.size(); second++)
        {
            mp[s[second]]++;
            while(mp.size() > 2)
            {
                if(mp[s[first]] == 1)
                {
                    mp.erase(s[first]);
                }
                else
                {
                    mp[s[first]]--;
                }
                first++;
            }
            ans = max(ans, second - first + 1);
        }
        return ans;
    }
};