// 1079. Letter Tile Possibilities
// https://leetcode.com/problems/letter-tile-possibilities/
// Difficulty: Medium
// Topics: Hash Table, String, Backtracking, Counting
//
// You have n tiles, where each tile has one letter tiles[i] printed on it.
// Return the number of possible non-empty sequences of letters you can make
// using the letters printed on those tiles.

class Solution {
private:
    int ans = 0;
   
public:
    void help(unordered_map<char, int>&mp, string& curr, string &tiles)
    {
        for(auto& a : mp)
        {
            if(a.second > 0)
            {
                a.second--;
                curr+=a.first;
                ans++;
                help(mp, curr, tiles);
                curr.pop_back();
                a.second++;
            }
        }

        return;
    }

    int numTilePossibilities(string tiles) {
        int size = tiles.size();
        unordered_map<char, int>mp;
        for(int i=0; i<size; i++)
        {
            mp[tiles[i]]++;
        }
        string curr = "";
        help(mp, curr, tiles);
        return ans;
    }
};