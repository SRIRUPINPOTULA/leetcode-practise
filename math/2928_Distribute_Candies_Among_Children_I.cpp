// 2928. Distribute Candies Among Children I

// You are given two positive integers n and limit.

// Return the total number of ways to distribute n candies among 3 children such that no child gets more than limit candies.
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ans = 0;

        for(int i=0; i<=limit; i++)
        {
            for(int j=0; j<=limit; j++)
            {
                for(int k=0; k<=limit; k++)
                {
                    if(i+j+k == n)
                        ans++;
                    else if(i+j+k > n)
                        break;
                }
            }
        }

        return ans;
    }
};