// 941. Valid Mountain Array
// https://leetcode.com/problems/valid-mountain-array/
// Difficulty: Easy
// Topics: Array, Two Pointers
//
// Given an array of integers arr, return true if and only if it is a valid
// mountain array.
//
// Recall that arr is a mountain array if and only if:
//   - arr.length >= 3
//   - There exists some i with 0 < i < arr.length - 1 such that:
//       - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//       - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int size = arr.size();
        for(int i = 1; i<size - 1; i++)
        {
            
            if(arr[i] > arr[i-1] &&  arr[i] > arr[i+1])
            {
                bool flag = true;
                for(int j = i; j >= 1; j--)
                {
                    if(arr[j] <= arr[j-1])
                    {
                        flag = false;
                        break;
                    }
                }

                for(int j = i+1; j <= size - 1 && flag == true; j++)
                {
                    if(arr[j] >= arr[j-1])
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag == true)
                    return true;
            }
        }
        return false;
    }
};