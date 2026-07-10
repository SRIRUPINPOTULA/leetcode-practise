// 2101. Detonate the Maximum Bombs

// You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt. This area is in the shape of a circle with the center as the location of the bomb.

// The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. xi and yi denote the X-coordinate and Y-coordinate of the location of the ith bomb, whereas ri denotes the radius of its range.

// You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range. These bombs will further detonate the bombs that lie in their ranges.

// Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed to detonate only one bomb.
class Solution {
public:

    void help(int node, vector<vector<int>>& bombs, vector<bool>&visited, int& counter)
    {
        visited[node] = true;
        for(int j = 0; j < bombs.size(); j++)
        {
            if(visited[j] == false && node != j)
            {
                long long int x = 1LL * bombs[node][0] - bombs[j][0];
                long long int y = 1LL * bombs[node][1] - bombs[j][1];
                long long int radius = 1LL * bombs[node][2] * bombs[node][2];
                if(x*x + y*y <= radius)
                {
                    counter+=1;
                    help(j, bombs, visited, counter);
                }
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans = INT_MIN;
        long size = bombs.size();
        
        for(int i = 0; i < size; i++)
        {
            vector<bool>visited(size, false);
            int counter = 0;
            help(i, bombs, visited, counter);
            ans = max(ans, counter+1);
        }

        return ans;
    }
};