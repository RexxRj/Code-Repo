class Solution
{

    /*int solve(int i, int j, int k, vector<int>& prices, vector<vector<int>>& dp)
    {
        if(i == prices.size() || j == k)
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        if(j%2 == 0)
        {
            return dp[i][j] = max(-prices[i] + solve(i+1,j+1,k,prices,dp),
            solve(i+1,j,k,prices,dp));
        }else
        {
            return dp[i][j] = max(prices[i] + solve(i+1,j+1,k,prices,dp),
            solve(i+1,j,k,prices,dp));
        }
    }*/

public:
    int maxProfit(int k, vector<int> &prices)
    {

        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
        vector<int> prev(2 * k + 1, 0), cur(2 * k + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 2 * k - 1; j >= 0; j--)
            {
                if (j % 2 == 0)
                {
                    cur[j] = max(-prices[i] + prev[j + 1], prev[j]);
                }
                else
                {
                    cur[j] = max(prices[i] + prev[j + 1], prev[j]);
                }
            }
            prev = cur;
        }

        return cur[0];
        // return solve(0,0,2*k,prices,dp);
    }
};