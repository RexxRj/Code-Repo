class Solution
{

    int solve(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (amount == 0)
            return 1;

        if (ind < 0)
            return 0;

        if (dp[ind][amount] != -1)
            return dp[ind][amount];

        int ntake = solve(ind - 1, amount, coins, dp);
        int take = 0;

        if (coins[ind] <= amount)
            take = solve(ind, amount - coins[ind], coins, dp);

        return dp[ind][amount] = ntake + take;
    }

public:
    int change(int amount, vector<int> &coins)
    {

        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));

        return solve(coins.size() - 1, amount, coins, dp);
    }
};