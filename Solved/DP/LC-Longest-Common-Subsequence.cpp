class Solution
{

    int solve(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp)
    {
        if (ind1 < 0 || ind2 < 0)
            return 0;

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        int ntake1 = solve(ind1 - 1, ind2, text1, text2, dp);
        int ntake2 = solve(ind1, ind2 - 1, text1, text2, dp);
        int take = 0;
        if (text1[ind1] == text2[ind2])
            take = 1 + solve(ind1 - 1, ind2 - 1, text1, text2, dp);

        return dp[ind1][ind2] = max(max(ntake1, take), ntake2);
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {

        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        vector<int> prev(n + 1, 0), cur(n + 1, 0);

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int ntake = max(prev[j], cur[j - 1]);
                int take = 0;
                if (text1[i - 1] == text2[j - 1])
                    take = 1 + prev[j - 1];

                cur[j] = max(ntake, take);
            }

            prev = cur;
        }

        return prev[n];
    }
};