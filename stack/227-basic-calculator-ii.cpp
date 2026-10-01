// 227. Basic Calculator II
// https://leetcode.com/problems/basic-calculator-ii/
// Difficulty: Medium
// Topics: Math, String, Stack
//
// Given a string s which represents an expression, evaluate this expression and
// return its value.
//
// The integer division should truncate toward zero.
//
// You may assume that the given expression is always valid. All intermediate
// results will be in the range of [-2^31, 2^31 - 1].
//
// Note: You are not allowed to use any built-in function which evaluates
// strings as mathematical expressions, such as eval().

class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        int size = s.size();
        int second = 0;
        string sign = "";
        unordered_set<char>signs;
        signs.insert('+');signs.insert('-');signs.insert('/');signs.insert('*');
        int number=0;
        stack<int>st;
        while(second < size)
        {
            if(signs.find(s[second]) != signs.end())
            {
                if(sign == "")
                {
                    sign = s[second];
                    st.push(number);
                }
                else
                {
                    if(sign == "/")
                    {
                        int dividend = st.top()/number;
                        st.pop();
                        st.push(dividend);
                    }
                    else if(sign == "*")
                    {
                        int multiply = st.top()*number;
                        st.pop();
                        st.push(multiply);
                    }
                    else if(sign == "-")
                    {
                        st.push(-1*number);
                    }
                    else
                        st.push(number);
                    sign = s[second];
                }
                number = 0;
            }
            else if(s[second] - '0' >=0 && s[second] - '0' <= 9)
            {
                number = number * 10 + (s[second]-'0');
            }
            second += 1;
        }
        if(sign == "/")
        {
            int dividend = st.top()/number;
            st.pop();
            st.push(dividend);
        }
        else if(sign == "*")
        {
            int multiply = st.top()*number;
            st.pop();
            st.push(multiply);
        }
        else if(sign == "-")
        {
            st.push(-1*number);
        }
        else
            st.push(number);

        while(st.empty() != true)
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};