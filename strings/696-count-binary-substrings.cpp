// 696. Count Binary Substrings
// https://leetcode.com/problems/count-binary-substrings/
// Difficulty: Easy
// Topics: String, Two Pointers
//
// Given a binary string s, return the number of non-empty substrings that have
// the same number of 0's and 1's, and all the 0's and all the 1's in these
// substrings are grouped consecutively.
//
// Substrings that occur multiple times are counted the number of times they
// occur.

class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int size = s.size();
        vector<pair<char, int>>len;
        int counter = 0;
        int i = 0;
        for(i=0; i<size; i++)
        {
            if(i+1 < size && s[i+1] != s[i])
            {
                len.push_back({s[i], counter+1});
                counter = 0;
            }
            else
                counter += 1;
        }
        len.push_back({s[i-1], counter});
        size = len.size();
        for(int i = 0; i < size; i++)
        {
            if(i + 1 < size && len[i].first != len[i+1].first)
            {
                ans += min(len[i].second, len[i+1].second);
            }
        }
        return ans;
    }   
};