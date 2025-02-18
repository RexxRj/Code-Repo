// Best Solution!!

class Solution
{

    /*int solve(int i, int trans, vector<int>& prices,vector<vector<int>>& dp)
    {
        if(i == prices.size() || trans == 4)
        return 0;

        if(dp[i][trans] != -1) return dp[i][trans];

        if(trans%2 == 0)
        {
            return dp[i][trans] = max(-prices[i] + solve(i+1,trans+1,prices,dp), solve(i+1,trans,prices,dp));
        }
        else
        {
            return dp[i][trans] = max(prices[i] + solve(i+1,trans+1,prices,dp),solve(i+1,trans,prices,dp));
        }
    }*/

public:
    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();

        // vector<vector<int>> dp(n+1,vector<int>(5,0));

        vector<int> prev(5, 0), cur(5, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 3; j >= 0; j--)
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

        return prev[0];
        // return solve(0,0,prices,dp);
    }
};