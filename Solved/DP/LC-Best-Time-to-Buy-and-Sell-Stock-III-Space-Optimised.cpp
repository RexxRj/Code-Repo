class Solution
{

    /*int solve(int i, int buy, int cap, vector<int>& prices,
              vector<vector<vector<int>>>& dp) {
        if (i == prices.size() || cap == 0)
            return 0;

        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        if (buy) {
            return dp[i][buy][cap] =
                       max(-prices[i] + solve(i + 1, 0, cap, prices,dp),
                           solve(i + 1, 1, cap, prices,dp));
        } else {
            return dp[i][buy][cap] =
                       max(prices[i] + solve(i + 1, 1, cap - 1, prices,dp),
                           solve(i + 1, 0, cap, prices,dp));
        }
    }*/

public:
    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();
        // vector<vector<vector<int>>> dp(
        //     n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        vector<vector<int>> prev(2, vector<int>(3, 0)), cur(2, vector<int>(3, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 1; buy >= 0; buy--)
            {
                for (int cap = 2; cap > 0; cap--)
                {
                    if (buy)
                    {
                        cur[buy][cap] = max(-prices[i] + prev[0][cap], prev[1][cap]);
                    }
                    else
                    {
                        cur[buy][cap] = max(prices[i] + prev[1][cap - 1], prev[0][cap]);
                    }
                }
            }

            prev = cur;
        }

        return prev[1][2];
        // return solve(0, 1, 2, prices, dp);
    }
};