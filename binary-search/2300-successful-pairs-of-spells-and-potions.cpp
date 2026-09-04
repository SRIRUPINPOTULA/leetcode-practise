// 2300. Successful Pairs of Spells and Potions
// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
// Difficulty: Medium
// Topics: Array, Two Pointers, Binary Search, Sorting
//
// You are given two positive integer arrays spells and potions, of length n and
// m respectively, where spells[i] represents the strength of the ith spell and
// potions[j] represents the strength of the jth potion.
// You are also given an integer success. A spell and potion pair is considered
// successful if the product of their strengths is at least success.
// Return an integer array pairs of length n where pairs[i] is the number of
// potions that will form a successful pair with the ith spell.

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        int n = spells.size();
        int m = potions.size();
        vector<int>res(n, -1);
        sort(potions.begin(), potions.end());
        for(int i=0; i<n; i++)
        {
            int ele = spells[i];
            int first = 0, second = m-1;
            int index = -1;
            while(first <= second)
            {
                int mid = first + (second - first)/2;
                if((long long)ele*potions[mid] >= success)
                {
                    index = mid;
                    second = mid - 1;
                }
                else
                {
                    first = mid + 1;
                }
            }
            
            if(index == -1)
                res[i] = 0;
            else
                res[i] = m - index;
        }
        return res;
    }
};