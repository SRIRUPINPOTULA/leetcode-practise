// 1642. Furthest Building You Can Reach
// https://leetcode.com/problems/furthest-building-you-can-reach/
// Difficulty: Medium
// Topics: Array, Dynamic Programming, Greedy, Heap (Priority Queue), BFS
//
// You are given an integer array heights representing the heights of buildings,
// some bricks, and some ladders.
// You start your journey from building 0 and move to the next building by
// possibly using bricks or ladders.
// While moving from building i to building i+1 (0-indexed):
//   - If the current building's height is greater than or equal to the next
//     building's height, you do not need a ladder or bricks.
//   - If the current building's height is less than the next building's height,
//     you can either use one ladder or (h[i+1] - h[i]) bricks.
//
// Return the furthest building index (0-indexed) you can reach if you use the
// given ladders and bricks optimally.

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i = 0;
        int size = heights.size();
        priority_queue<int>pq;
        while(i+1 < size)
        {
            int curr = heights[i];
            int next = heights[i+1];
            if(next - curr <= 0)
                i++;
            else
            {
                bricks -= (next -curr);
                pq.push(next - curr);

                while(bricks < 0 && ladders > 0)
                {
                    bricks += pq.top();
                    ladders -= 1;
                    pq.pop();
                }

                if(bricks < 0)
                {
                    return i;
                }
                i++;
            }
        }
        return size - 1;
    }
};