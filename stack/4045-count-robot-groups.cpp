// 4045. Count Robot Groups
// https://leetcode.com/problems/count-robot-groups/
// Difficulty: Medium
// Topics: Array, Stack, Monotonic Stack
//
// You are given a strictly increasing integer array position, where position[i]
// is the initial position of the ith robot at time t = 0.
// You are also given an integer array speed, where speed[i] is the constant
// speed of the ith robot in units per second, and an integer distance.
// Time is continuous and measured in seconds. A robot or group with speed v
// moves v * t units to the right over any interval of t seconds.
// Whenever the distance between two robots or groups becomes at most distance,
// they merge into a single group.
// If multiple robots or groups satisfy the merging condition at the same time,
// all merges happen simultaneously. In particular, every connected collection
// of robots or groups whose consecutive positions differ by at most distance
// merges into one group.
// After a merge, the resulting group takes the current position and speed of the
// rightmost robot in that group. Once merged, robots never separate.
// Return the number of groups remaining after all possible merges have occurred.

class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int size = position.size();
        vector<pair<long long, long long>>st;

        for(int i=size-1; i>=0; i--)
        {
            long long backPos = position[i];
            long long grpSpeed = speed[i];
            long long mySpeed = speed[i];
            while(st.empty() != true)
            {
                long long topBack = st.back().first;
                long long topSpeed = st.back().second;
                long long gap = topBack - backPos;
                bool merge = (gap <= (long long)distance) || (mySpeed > topSpeed);

                if(merge)
                {
                    grpSpeed = topSpeed;
                    mySpeed = topSpeed;
                    st.pop_back();
                }
                else
                    break;
            }
            st.push_back({backPos, grpSpeed});
        }

        return st.size();
    }
};