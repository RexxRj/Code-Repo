class Solution
{

    /*int solve(int i, int j, int& fee, vector<int>& prices, vector<vector<int>>& dp)
    {
        if(i == prices.size())
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        if(j)
        {
            return dp[i][j] = max(-prices[i] + solve(i+1,0,fee,prices,dp),solve(i+1,1,fee,prices,dp));
        }else
        {
            return dp[i][j] = max(prices[i] - fee + solve(i+1,1,fee,prices,dp),solve(i+1,0,fee,prices,dp));
        }
    }*/

public:
    int maxProfit(vector<int> &prices, int fee)
    {

        int n = prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,0));
        vector<int> prev(2, 0), cur(2, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 2; j++)
            {
                if (j)
                {
                    cur[j] = max(-prices[i] + prev[0], prev[1]);
                }
                else
                {
                    cur[j] = max(prices[i] - fee + prev[1], prev[0]);
                }
            }
            prev = cur;
        }

        return prev[1];
        // return solve(0,1,fee,prices,dp);
    }
};