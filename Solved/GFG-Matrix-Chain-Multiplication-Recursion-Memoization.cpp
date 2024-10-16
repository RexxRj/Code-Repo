// User function Template for C++

class Solution
{
    int solve(int start, int end, int arr[], vector<vector<int>> &dp)
    {
        if (start == end)
            return 0;

        if (dp[start][end] != -1)
            return dp[start][end];

        int res = 1e9;

        for (int k = start; k < end; k++)
        {
            int op = arr[start - 1] * arr[k] * arr[end] + solve(start, k, arr, dp) + solve(k + 1, end, arr, dp);

            res = min(res, op);
        }

        return dp[start][end] = res;
    }

public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here

        vector<vector<int>> dp(N, vector<int>(N, -1));

        return solve(1, N - 1, arr, dp);
    }
};