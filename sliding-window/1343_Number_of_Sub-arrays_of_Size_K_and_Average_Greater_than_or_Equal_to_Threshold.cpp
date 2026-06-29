// 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
// Given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or equal to threshold.

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0;
        int currSum = 0;
        int index = 0;
        for(int i=0; i<k; i++)
        {
            currSum += arr[i];
        }

        if((double)currSum/k >= (double)threshold)
            res++;

        for(int i=k; i<arr.size(); i++)
        {
            currSum -= arr[index];
            index++;
            currSum += arr[i];
            if((double)currSum/k >= (double)threshold)
                res++;
        }

        return res;
    }
};