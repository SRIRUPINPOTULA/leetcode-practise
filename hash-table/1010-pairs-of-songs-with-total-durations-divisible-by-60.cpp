// 1010. Pairs of Songs With Total Durations Divisible by 60
// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
// Difficulty: Medium
// Topics: Array, Hash Table, Counting
//
// You are given a list of songs where the ith song has a duration of time[i]
// seconds.
//
// Return the number of pairs of songs for which their total duration in seconds
// is divisible by 60. Formally, we want the number of indices i, j such that
// i < j with (time[i] + time[j]) % 60 == 0.

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        int size = time.size();
        unordered_map<int, int>mp;
        for(int i=0; i<size; i++)
        {
            int rem = time[i]%60;
            if(rem == 0)
            {
                ans += mp[rem];
                mp[rem]++;
                continue;
            }
            if(mp.find(60 - rem) != mp.end())
            {
                //cout << i << " " <<rem << " " << (60 - rem) << endl; 
                ans += mp[60 - rem];
            }
            mp[rem]++;
        }   
        
        return ans;
    }
};