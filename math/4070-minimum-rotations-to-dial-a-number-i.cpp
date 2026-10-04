// 4070. Minimum Rotations to Dial a Number I
// https://leetcode.com/problems/minimum-rotations-to-dial-a-number-i/
// Difficulty: Easy
// Topics: String, Math, Simulation
//
// You are given a string s of length 10 consisting of digits.
//
// The dial contains the digits 0 through 9 in order and is circular, so 0 and 9
// are adjacent. The pointer initially points to 0.
//
// To dial each digit of s in order, rotate the pointer until it points to that
// digit. Each rotation moves the pointer to an adjacent digit, and you may
// rotate in either direction. Dialing a digit that the pointer already points
// to requires no rotations.
//
// Return the minimum total number of rotations needed to dial every digit of s.

class Solution {
private:
    vector<int>digits = {0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9};
public:
    int help(int currIndex, int number)
    {
        int index = currIndex;
        int left = 0, right = 0;
        //right pass
        for(int j = currIndex; j<digits.size(); j++)
        {
            if(digits[j] == number)
                break;
            left += 1;
        }
        //left
        for(int j = currIndex+10; j>=0; j--)
        {
            if(digits[j] == number)
                break;
            right += 1;
        }
        return min(left, right);
    }
    int minRotations(string s) {
        int ans = 0;
        int currIndex = 0;
        for(int i = 0; i < 10; i++)
        {
            int number = s[i] - '0';
            int steps = help(currIndex, number);
            ans += steps;
            currIndex = number;
        }
        return ans;
    }
};