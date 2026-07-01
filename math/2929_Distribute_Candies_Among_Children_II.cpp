// 2929. Distribute Candies Among Children II
// You are given two positive integers n and limit.

// Return the total number of ways to distribute n candies among 3 children such that no child gets more than limit candies.

class Solution {
public:

    long long distributeCandies(int n, int limit) {
        long long ans = 0;

        for(int i = 0; i <= min(limit, n); i++)
        {
            int bMin = max(0, n - i - limit);
            int bMax = min(limit, n - i);
            if(bMax >= bMin)
                ans += (bMax - bMin + 1);
        }

        return ans;
    }
};