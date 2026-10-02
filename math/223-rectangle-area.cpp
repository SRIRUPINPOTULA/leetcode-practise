// 223. Rectangle Area
// https://leetcode.com/problems/rectangle-area/
// Difficulty: Medium
// Topics: Math, Geometry
//
// Given the coordinates of two rectilinear rectangles in a 2D plane, return the
// total area covered by the two rectangles.
//
// The first rectangle is defined by its bottom-left corner (ax1, ay1) and its
// top-right corner (ax2, ay2).
//
// The second rectangle is defined by its bottom-left corner (bx1, by1) and its
// top-right corner (bx2, by2).

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int ans = 0;
        int diff = ay2 - ay1;
        int diff2 = ax2 - ax1;

        ans = ans + (diff * diff2);

        diff = by2 - by1;
        diff2 = bx2 - bx1;

        ans = ans + diff * diff2;
        
        diff = max(0, min(ay2, by2) - max(ay1, by1));
        diff2 = max(0, min(ax2,bx2) - max(ax1,bx1));
        ans = ans - abs(diff * diff2);
        
        return ans;
    }
};