class Solution
{

public:
    int coinChange(vector<int> &coins, int amount)
    {

        int n = coins.size();

        vector<vector<int>> dp(2, vector<int>(amount + 1, 0));

        for (int j = 0; j <= amount; j++)
        {
            dp[n % 2][j] = j == 0 ? 0 : 1e9;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= amount; j++)
            {
                int ntake = dp[(i + 1) % 2][j];

                if (coins[i] <= j)
                    ntake = min(ntake, 1 + dp[i % 2][j - coins[i]]);

                dp[i % 2][j] = ntake;
            }
        }

        int ans = dp[0][amount];

        return ans == 1e9 ? -1 : ans;
    }
};