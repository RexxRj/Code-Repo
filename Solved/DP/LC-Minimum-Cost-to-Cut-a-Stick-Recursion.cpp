class Solution
{

    int solve(int start, int end, vector<int> &cuts, vector<vector<int>> &dp)
    {

        if (dp[start][end] != -1)
            return dp[start][end];

        int minCost = 1e9;

        for (int i = start + 1; i < end; i++)
            minCost = min(minCost, cuts[end] - cuts[start] + solve(start, i, cuts, dp) + solve(i, end, cuts, dp));

        return dp[start][end] = minCost == 1e9 ? 0 : minCost;
    }

public:
    int minCost(int n, vector<int> &cuts)
    {

        vector<int> newCuts = cuts;
        newCuts.push_back(0);
        newCuts.push_back(n);
        sort(newCuts.begin(), newCuts.end());

        n = newCuts.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, n - 1, newCuts, dp);
    }
};