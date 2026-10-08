// 12. Integer to Roman
// https://leetcode.com/problems/integer-to-roman/
// Difficulty: Medium
// Topics: Hash Table, Math, String
//
// Seven different symbols represent Roman numerals with the following values:
//   Symbol  Value
//   I       1
//   V       5
//   X       10
//   L       50
//   C       100
//   D       500
//   M       1000
//
// Roman numerals are formed by appending the conversions of decimal place
// values from highest to lowest. Converting a decimal place value into a Roman
// numeral has the following rules:
//   1. If the value does not start with 4 or 9, select the symbol of the
//      maximal value that can be subtracted from the input, append that symbol
//      to the result, subtract its value, and convert the remainder to a Roman
//      numeral.
//   2. If the value starts with 4 or 9 use the subtractive form representing
//      one symbol subtracted from the following symbol, for example, 4 is 1 (I)
//      less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the
//      following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC),
//      400 (CD) and 900 (CM).
//   3. Only powers of 10 (I, X, C, M) can be appended consecutively at most 3
//      times to represent multiples of 10. You cannot append 5 (V), 50 (L), or
//      500 (D) multiple times. If you need to append a symbol 4 times use the
//      subtractive form.
//
// Given an integer, convert it to a Roman numeral.

class Solution {
private:
    unordered_map<int, string>mp;
public:
    string intToRoman(int num) {
        mp[1] = "I";mp[5] = "V"; mp[10] = "X"; mp[50] = "L"; mp[100] = "C"; mp[500] = "D"; mp[1000] = "M"; mp[4] = "IV"; mp[9] = "IX"; mp[40] = "XL"; mp[90] = "XC"; mp[400] = "CD"; mp[900] = "CM";
        int ans = 1;
        stack<int>st;
        while(num > 0)
        {
            int digit = num%10;
            st.push(digit*ans);
            ans = ans*10;
            num /= 10;
        }

        string res = "";
        while(st.empty() != true)
        {
            int number = st.top();
            // cout << number << endl;
            st.pop();
            if(mp.find(number) != mp.end())
            {
                res += mp[number];
            }
            else
            {
                string temp = "";
                if(number > 1000)
                {
                    int q = number/1000;
                    if(q < 5)
                    {
                        for(int i=0; i<q; i++)
                            temp += mp[1000];
                    }
                }
                else if(number > 500)
                {
                    temp = mp[500];
                    int q = number/1000;

                    int diff = (number - 500)/100;
                    for(int i=0; i<diff; i++)
                        temp+=mp[100];
                }
                else if(number > 100)
                {
                    int q = number/100;
                    if(q < 5)
                    {
                        for(int i=0; i<q; i++)
                            temp += mp[100];
                    }
                    else
                    {
                        temp = mp[100];
                        int diff = (number - 100)/50;
                        for(int i=0; i<diff; i++)
                            temp+=mp[50];
                    }
                    
                }
                else if(number > 50){
                    temp = mp[50];
                    int diff = (number - 50)/10;
                    for(int i=0; i<diff; i++)
                        temp+=mp[10];
                }
                else if(number > 10)
                {
                    
                    int q = number/10;
                    if(q < 5)
                    {
                        for(int i=0; i<q; i++)
                            temp += mp[10];
                    }
                    else
                    {
                        temp = mp[10];
                        int diff = (number - 10)/5;
                        for(int i=0; i<diff; i++)
                            temp+=mp[5];
                    }
                }
                else if(number > 5)
                {
                    temp = mp[5];
                    int diff = (number - 5)/1;
                    for(int i=0; i<diff; i++)
                        temp+=mp[1];
                }
                else if(number > 1)
                {
                    for(int i=1; i<=number; i++)
                    {
                        temp+=mp[1];
                    }
                }
                res += temp;
            }
            
        }
        return res;
    }
};