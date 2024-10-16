class Solution
{

    int solve(int ind, vector<int> &coins, int amount, vector<vector<int>> &dp)
    {
        if (ind == coins.size())
        {
            return amount == 0 ? 0 : 1e9;
        }

        if (dp[ind][amount] != -1)
            return dp[ind][amount];

        int ntake = solve(ind + 1, coins, amount, dp);

        if (coins[ind] <= amount)
            ntake = min(ntake, 1 + solve(ind, coins, amount - coins[ind], dp));

        return dp[ind][amount] = ntake;
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(0, coins, amount, dp);

        return ans == 1e9 ? -1 : ans;
    }
};