// 475. Heaters
// https://leetcode.com/problems/heaters/
// Difficulty: Medium
// Topics: Array, Two Pointers, Binary Search, Sorting
//
// Winter is coming! During the contest, your first job is to design a standard
// heater with a fixed warm radius to warm all the houses.
//
// Every house can be warmed, as long as the house is within the heater's warm
// radius range.
//
// Given the positions of houses and heaters on a horizontal line, return the
// minimum radius standard of heaters so that those heaters could cover all
// houses.
//
// Notice that all the heaters follow your radius standard, and the warm radius
// will be the same.

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans = 0;
        int size = houses.size();
        vector<int>greater(size, -1);
        sort(heaters.begin(), heaters.end());
        for(int i=0; i<size; i++)
        {
            int h = houses[i];
            int low = 0, high = heaters.size()-1;
            int dist = INT_MAX;
            while(low <= high)
            {
                int mid = low + (high - low)/2;
                dist = min(dist, abs(h - heaters[mid]));
                if(heaters[mid] == h)
                    break;
                else if(heaters[mid] > h)
                    high = mid - 1;
                else
                    low = mid+1;
            }
            greater[i] = dist;
        }
        for(int i=0; i<size; i++)
        {
            ans = max(ans, greater[i]);
        }
        return ans;
    }
};