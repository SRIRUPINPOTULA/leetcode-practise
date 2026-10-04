// 593. Valid Square
// https://leetcode.com/problems/valid-square/
// Difficulty: Medium
// Topics: Math, Geometry
//
// Given the coordinates of four points in 2D space p1, p2, p3 and p4, return
// true if the four points construct a square.
//
// The coordinate of a point pi is represented as [xi, yi]. The input is not
// given in any order.
//
// A valid square has four equal sides with positive length and four equal
// angles (90-degree angles).

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int ans = 0;
        vector<vector<int>>points = {p1, p2, p3, p4};
        unordered_map<int, vector<vector<int>>>mp;
        int size = points.size();
        long long side1 = 0;
        long long diag1 = 0;
        for(int i=0; i<size; i++)
        {
            for(int j=i+1; j<size; j++)
            {
                long long s1 = (points[i][0]-points[j][0])*(points[i][0]-points[j][0]) + (points[i][1]-points[j][1]) * (points[i][1]-points[j][1]);
                mp[abs(s1)].push_back({i, j});
                mp[abs(s1)].push_back({j, i});
            }
        }
       
        if(mp.size() != 2)
            return false;
        
        for(auto a : mp)
        {
            if(side1 == 0)
                side1 = a.first;
            else if(side1 != 0 && diag1 == 0)
                diag1 = a.first;
        }
        if(side1 > diag1)
            swap(side1, diag1);
        if(diag1 != side1*2)
            return false;
        return true;
    }
};