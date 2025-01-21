
bool solve(int ind, int k, vector<int> &a, vector<vector<int>> &dp)
{
    if (k == 0)
        return true;

    if (ind < 0)
    {
        if (k == 0)
            return true;
        else
            return false;
    }

    if (dp[ind][k] != -1)
        return dp[ind][k];

    bool ntpick = solve(ind - 1, k, a, dp);
    bool pick = false;

    if (a[ind] <= k)
        pick = solve(ind - 1, k - a[ind], a, dp);

    return dp[ind][k] = pick || ntpick;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return solve(n - 1, k, a, dp);
}