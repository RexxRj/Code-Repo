class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {

        vector<int> newCuts = cuts;
        newCuts.push_back(0);
        newCuts.push_back(n);
        sort(newCuts.begin(), newCuts.end());

        n = newCuts.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                int minCost = 1e9;

                for (int k = i + 1; k < j; k++)
                    minCost = min(minCost, newCuts[j] - newCuts[i] + dp[i][k] + dp[k][j]);

                dp[i][j] = minCost == 1e9 ? 0 : minCost;
            }
        }

        return dp[0][n - 1];
    }
};