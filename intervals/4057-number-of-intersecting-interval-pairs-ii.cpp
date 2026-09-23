// 4057. Number of Intersecting Interval Pairs II
// https://leetcode.com/problems/number-of-intersecting-interval-pairs-ii/
// Difficulty: Medium
// Topics: Array, Sorting, Interval
//
// You are given a 2D integer array intervals of n elements, where
// intervals[i] = [starti, endi] represents the closed interval from starti to
// endi.
//
// Return the number of pairs of indices (i, j) such that 0 <= i < j < n and
// intervals[i] and intervals[j] intersect.
//
// Two intervals intersect if they have at least one point in common, including
// when they only share an endpoint.

class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        long long ans = 0;
        long long size = intervals.size();
        vector<int>start(size);
        vector<int>end(size);
        ans = size * (size-1)/2;
        for(int i = 0; i < size; i++)
        {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int j = 0;

        for(int i=0; i<size; i++)
        {
            while(j < size && end[j] < start[i])
            {
                j++;
            }
            ans = ans - j;
        }
        
        return ans;
    }
};