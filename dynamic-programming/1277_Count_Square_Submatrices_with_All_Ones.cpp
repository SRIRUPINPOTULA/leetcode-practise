// 1277. Count Square Submatrices with All Ones

// Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

// Approach - 1:
class Solution {
public:

    bool help(int r, int c, int tR, int tC, vector<vector<int>>& matrix)
    {
        for(int k=r; k<=tR; k++)
        {
            for(int l=c; l<=tC; l++)
            {
                if(matrix[k][l] != 1)
                    return false;
            }
        }
        return true;
    }

    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int a = 0; a<m; a++)
        {
            for(int b=0; b<n; b++)
            {
                int i=a, j=b;
                if(matrix[i][j] == 1)
                {
                    ans += 1;
                    i-=1, j-=1;
                    while(i >= 0 && j >= 0)
                    {
                        if(help(i, j, a, b, matrix))
                            ans+=1;
                        else 
                            break;
                        i-=1;
                        j-=1;
                    }
                }
            }
        }
        return ans;
    }
};

// Approach - 2:
class Solution {
private:
    vector<vector<int>>dp;

public:

    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, 0));
        for(int i = 0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == 1)
                {
                    int diag = 0;
                    if(i-1 >= 0 && j-1 >= 0)
                        diag = dp[i-1][j-1];
                    int top = 0;
                    if(i-1>=0)
                        top = dp[i-1][j];
                    int left = 0;
                    if(j-1>=0)
                        left = dp[i][j-1];
                    int minimum = min(top, diag);
                    dp[i][j] = 1 + min(minimum, left);
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};
