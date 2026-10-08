// 1190. Reverse Substrings Between Each Pair of Parentheses
// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// Difficulty: Medium
// Topics: String, Stack, Recursion
//
// You are given a string s that consists of lower case English letters and
// brackets.
//
// Reverse the strings in each pair of matching parentheses, starting from the
// innermost one.
//
// Your result should not contain any brackets.

class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        // stack<char>st;
        string temp = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ')')
            {
                string curr = "";
                // while(st.top() != '(')
                // {
                //     curr += st.top();
                //     st.pop();
                // }
                // st.pop();
                // for(int j = 0; j < curr.size(); j++)
                //     st.push(curr[j]);
                while(res.back() != '(')
                {
                    curr += res.back();
                    res.pop_back();
                }
                res.pop_back();
                res += curr;
            }
            else
                res += s[i];
        }

        // while(st.empty() != true)
        // {
        //     res+=st.top();
        //     st.pop();
        // }
        // reverse(res.begin(), res.end());
        return res;
    }
};