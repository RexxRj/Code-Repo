class Solution
{

    int solve(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        if (j < 0)
        {
            return 0;
        }

        if (i < 0)
        {

            while (j >= 0 && p[j] == '*')
                j--;
            if (j < 0)
                return 0;
            else
                return 1e9;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans1 = solve(i - 1, p.size() - 1, s, p, dp), ans2 = 1e9, ans3 = 1e9;

        if (s[i] == p[j])
            ans2 = 1 + solve(i - 1, j - 1, s, p, dp);
        else if (p[j] == '*')
        {
            // cout<<j<<" "<<res<<endl;
            ans3 = solve(i, j - 1, s, p, dp);
            for (int ind = i; ind >= 0; ind--)
            {
                ans3 = min(ans3, i - ind + 1 + solve(ind - 1, j - 1, s, p, dp));
            }
        }

        return dp[i][j] = min(ans1, min(ans2, ans3));
    }

public:
    int shortestMatchingSubstring(string s, string p)
    {

        int m = s.size(), n = p.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int ans = solve(m - 1, n - 1, s, p, dp);

        for (int j = 1; j <= n; j++)
            dp[0][j] = 1e9;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int ans1 = dp[i - 1][n], ans2 = 1e9, ans3 = 1e9;

                if (s[i - 1] == p[j - 1])
                    ans2 = 1 + dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                {
                    ans3 = dp[i][j - 1];
                    for (int ind = i; ind > 0; ind--)
                    {
                        ans3 = min(ans3, i - ind + 1 + dp[ind - 1][j - 1]);
                    }
                }

                dp[i][j] = min(ans1, min(ans2, ans3));
            }
        }

        return dp[m][n] == 1e9 ? -1 : dp[m][n];
    }
};