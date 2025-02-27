class Solution
{

    int solve(int mask, int X, vector<int> &str, int K, int n)
    {
        if (mask == (1 << n) - 1)
            return 0;

        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (!(mask & (1 << i)))
            {
                int t = ceil((double)str[i] / X);
                ans = min(ans, t + solve(mask | (1 << i), X + K, str, K, n));
            }
        }

        return ans;
    }

public:
    int findMinimumTime(vector<int> &str, int K)
    {

        return solve(0, 1, str, K, str.size());
    }
};