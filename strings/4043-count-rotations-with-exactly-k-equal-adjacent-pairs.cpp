// 4043. Count Rotations With Exactly K Equal Adjacent Pairs
// https://leetcode.com/problems/count-rotations-with-exactly-k-equal-adjacent-pairs/
// Difficulty: Easy
// Topics: String, Counting
//
// You are given a string s of length n and an integer k.
// A cyclic rotation of s is obtained by choosing a prefix of s whose length is
// between 0 and n - 1 (inclusive), and moving it to the end of the string while
// preserving the order of all characters.
// For every cyclic rotation of s, let its score be the number of indices i such
// that 0 <= i < n - 1 and the characters at positions i and i + 1 are equal.
// Return the number of cyclic rotations of s whose score equals k.

class Solution {
public:
    int help(string prefix)
    {
        int size = prefix.size();
        int count = 0;
        for(int i=1; i < size; i++)
        {
            if(prefix[i] == prefix[i-1])
                count++;
        }
        return count;
    }
    
    int countRotations(string s, int k) {
        int ans = 0;
        string temp = "";
        int size = s.size();
        for(int i=0; i<size; i++)
        {
            temp = s[i];
            string suffix = s.substr(i+1, size - i);
            string prefix = s.substr(0, i);
            temp = temp + suffix + prefix;
            int count = help(temp);
            if(count == k)
                ans++;
            temp = "";
        }
        return ans;
    }
};