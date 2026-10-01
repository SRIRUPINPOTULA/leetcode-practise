// 340. Longest Substring with At Most K Distinct Characters
// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
// Difficulty: Medium
// Topics: Hash Table, String, Sliding Window
//
// Given a string s and an integer k, return the length of the longest
// substring of s that contains at most k distinct characters.

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ans = 0;
        int size = s.size();
        int first= 0 , second = 0;
        if(k == 0)
            return 0;
        unordered_map<char, int>mp;
        int count = 0;
        
        while(second < size)
        {
            if(mp.find(s[second]) == mp.end())
            {
                mp[s[second]]++;
                count+=1;
            }
            else
            {
                mp[s[second]]++;
            }   
            while(first <= second && count>k)
            {
                if(mp[s[first]] == 1)
                {
                    count--;
                    mp.erase(s[first]);
                }
                else
                    mp[s[first]]--;
                first += 1;
            }
            if(count <= k)
            {
                ans = max(ans, second - first + 1);
            }
                
            second++;
        }
        return ans;
    }
};