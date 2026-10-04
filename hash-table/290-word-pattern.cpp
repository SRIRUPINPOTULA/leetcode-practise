// 290. Word Pattern
// https://leetcode.com/problems/word-pattern/
// Difficulty: Easy
// Topics: Hash Table, String
//
// Given a pattern and a string s, find if s follows the same pattern.
//
// Here follow means a full match, such that there is a bijection between a
// letter in pattern and a non-empty word in s. Specifically:
//   - Each letter in pattern maps to exactly one unique word in s.
//   - Each unique word in s maps to exactly one letter in pattern.
//   - No two letters map to the same word, and no two words map to the same
//     letter.

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string temp = "";
        int j = 0;
        unordered_map<char, string>mp1;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                if(mp1.find(pattern[j]) == mp1.end())
                {
                    mp1[pattern[j]] = temp;
                }
                j++;
                temp = "";
            }
            else
                temp += s[i];
        }
        mp1[pattern[j]] = temp;
        j++;

        unordered_map<string, int>freq;
        for(auto a : mp1)
        {
            freq[a.second]++;
        }

        if(mp1.size() != freq.size())
            return false;
        
        string res = "";
        for(int i=0; i<pattern.size(); i++)
        {
            res = res + mp1[pattern[i]];
            res = res + " ";
        }
        res.pop_back();

        if(res == s)
            return true;
        
        return false;
    }
};