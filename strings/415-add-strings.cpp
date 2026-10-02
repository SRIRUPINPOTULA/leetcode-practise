// 415. Add Strings
// https://leetcode.com/problems/add-strings/
// Difficulty: Easy
// Topics: Math, String, Simulation
//
// Given two non-negative integers, num1 and num2 represented as string, return
// the sum of num1 and num2 as a string.
//
// You must solve the problem without using any built-in library for handling
// large integers (such as BigInteger). You must also not convert the inputs to
// integers directly.

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        if(num1.size() > num2.size())
            swap(num1, num2);
        
        int i = num1.size()-1;
        int j = num2.size()-1;
        int carry = 0;
        while(i >=0 && j>=0)
        {
            int sum = (num1[i]-'0') + (num2[j] - '0') + carry;
            carry = sum/10;
            int digit = sum%10;
            ans  = char(digit + '0') + ans;
            i--;
            j--;
        }
        while(j>=0)
        {
            int sum = (num2[j] - '0') + carry;
            carry = sum/10;
            int digit = sum%10;
            ans  = char(digit + '0') + ans;
            j--;
        }
        if(carry > 0)
            ans = char(carry + '0') + ans;
        return ans;
    }
};