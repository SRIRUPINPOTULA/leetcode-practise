// 845. Longest Mountain in Array
// https://leetcode.com/problems/longest-mountain-in-array/
// Difficulty: Medium
// Topics: Array, Two Pointers, Enumeration
//
// You may recall that an array arr is a mountain array if and only if:
//   - arr.length >= 3
//   - There exists some index i (0-indexed) with 0 < i < arr.length - 1 such
//     that:
//       - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//       - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
//
// Given an integer array arr, return the length of the longest subarray, which
// is a mountain. Return 0 if there is no mountain subarray.
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans = 0;
        int size = arr.size();
        int i = 1;
        for(int i = 1; i < size - 1; i++)
        {
            if(arr[i] > arr[i-1] && arr[i+1] < arr[i])
            {
                int start = i; 
                while(start-1 >=0 && arr[start] > arr[start-1])
                {
                    start--;
                }
                int end = i;
                while(end+1 <= size-1 && arr[end] > arr[end+1])
                {
                    end++;
                }
                ans = max(ans, end - start + 1);
            }
        }
        return ans;
    }
};
