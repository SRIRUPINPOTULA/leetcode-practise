// 1209. Remove All Adjacent Duplicates in String II
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
// Difficulty: Medium
// Topics: String, Stack
//
// You are given a string s and an integer k, a k duplicate removal consists of
// choosing k adjacent and equal letters from s and removing them, causing the
// left and the right side of the deleted substring to concatenate together.
//
// We repeatedly make k duplicate removals on s until we no longer can.
//
// Return the final string after all such duplicate removals have been made. It
// is guaranteed that the answer is unique.

class Solution {
public:
    string removeDuplicates(string s, int k) {
        string res = "";
        int size = s.size();
        stack<pair<char, int>>st;
        st.push({s[0], 1});
        for(int i=1; i<size; i++)
        {
            if(st.empty() != true && st.top().first == s[i])
            {
                st.push({s[i], st.top().second+1});
            }
            else
            {
                st.push({s[i], 1});
            }
            if(st.empty() != true && st.top().second == k)
            {
                for(int j=0; j<k; j++)
                {
                    st.pop();
                }
            }
        }
        while(st.empty()!=true)
        {
            res+=st.top().first;
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};