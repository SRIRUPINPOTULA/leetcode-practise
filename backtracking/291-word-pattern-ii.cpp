// 291. Word Pattern II
// https://leetcode.com/problems/word-pattern-ii/
// Difficulty: Medium
// Topics: Hash Table, String, Backtracking, Trie
//
// Given a pattern and a string s, return true if s matches the pattern.
//
// A string s matches a pattern if there is some bijective mapping of single
// characters to non-empty strings such that if each character in pattern is
// replaced by the string it maps to, then the resulting string is s. A
// bijective mapping means that no two characters map to the same string, and no
// character maps to two different strings.

class Solution {
private:
    unordered_map<char, int>uniq;
    unordered_map<char, string>letterToWord;
public:
    bool help(string &pattern, int patternIndex, string& s, int index, unordered_map<string, int>temp, int spaces)
    {
        if(spaces == 0)
        {
            string res = "";
            unordered_map<string, unordered_set<char>>wordToLetter;
            for(auto a : pattern)
            {
                res += letterToWord[a];
                wordToLetter[letterToWord[a]].insert(a);
            }
            
            if(res == s)
            {
                for(auto a : wordToLetter)
                {
                    if(a.second.size() > 1)
                        return false;
                }
                return true;
            }
            return false;
        }

        string curr = "";
        for(int i = index; i<s.size(); i++)
        {
            curr += s[i];
            temp[curr]++;
            if(letterToWord.find(pattern[patternIndex]) == letterToWord.end())
                letterToWord[pattern[patternIndex]] = curr;
            patternIndex += 1;
            if(help(pattern, patternIndex,s, i+1, temp, spaces-1))
                return true;
            patternIndex -= 1;
            temp.erase(curr);
            letterToWord.erase(pattern[patternIndex]);
        }

        return false;
    }
    bool wordPatternMatch(string pattern, string s) {
        for(int i=0; i<pattern.size(); i++)
            uniq[pattern[i]]++;
        unordered_map<string, int>temp;
        return help(pattern, 0, s, 0, temp, pattern.size());
    }
};