// 187. Repeated DNA Sequences
// https://leetcode.com/problems/repeated-dna-sequences/
// Difficulty: Medium
// Topics: Hash Table, String, Bit Manipulation, Sliding Window, Hash Function
//
// The DNA sequence is composed of a series of nucleotides abbreviated as 'A',
// 'C', 'G', and 'T'.
//   For example, "ACGAATTCCG" is a DNA sequence.
// When studying DNA, it is useful to identify repeated sequences within the DNA.
// Given a string s that represents a DNA sequence, return all the 10-letter-long
// sequences (substrings) that occur more than once in a DNA molecule. You may
// return the answer in any order.

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>res;
        int size = s.size();
        string temp = "";
        unordered_map<string, int>mp;
        int first = 0, second = 9;
        while (second < size)
        {
            int len = second - first + 1;
            if(len == 10)
            {
                string temp = s.substr(first, 10);
                mp[temp]++;
            }
            second++;
            first++;
        }
        for(auto a : mp)
        {
            if(a.second > 1)
                res.push_back(a.first);
        }
        return res;
    }
};