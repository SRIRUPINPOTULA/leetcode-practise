// 2516. Take K of Each Character From Left and Right

// You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.

// Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.
class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char, int>mp;
        int size = s.size();
        for(int i=0; i<s.size(); i++)
            mp[s[i]]++;

        if(mp['a'] < k || mp['b'] < k || mp['c'] < k)
            return -1;
        
        int left = 0;
        int right = 0;
        int res = INT_MAX;
        for(right = 0; right < s.size(); right++)
        {
            mp[s[right]]--;
            while(mp['a'] < k || mp['b'] < k || mp['c'] < k)
            {
                mp[s[left]]++;
                left += 1;
            }
            res = min(res, size-(right-left+1));
        }

        return res;
    }
};