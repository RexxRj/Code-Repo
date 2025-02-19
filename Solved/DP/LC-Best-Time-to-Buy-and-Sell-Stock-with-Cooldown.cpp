class Solution
{

    /*int solve(int i, int j, vector<int>& prices,vector<vector<int>>& dp)
    {
        if(i == prices.size())
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        if(j == 2)
        {
            return dp[i][j] = max(-prices[i] + solve(i+1,j-1,prices,dp),solve(i+1,j,prices,dp));
        }else if(j == 1)
        {
            return dp[i][j] = max(prices[i] + solve(i+1,j-1,prices,dp),solve(i+1,j,prices,dp));
        }else
        {
            return dp[i][j] = solve(i+1,j+2,prices,dp);
        }
    }*/

public:
    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(3,0));
        vector<int> prev(3, 0), cur(3, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j == 2)
                {
                    cur[j] = max(-prices[i] + prev[j - 1], prev[j]);
                }
                else if (j == 1)
                {
                    cur[j] = max(prices[i] + prev[j - 1], prev[j]);
                }
                else
                {
                    cur[j] = prev[j + 2];
                }
            }
            prev = cur;
        }

        return prev[2];

        // return solve(0,2,prices,dp);
    }
};