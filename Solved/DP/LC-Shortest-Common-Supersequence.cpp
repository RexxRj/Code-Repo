class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {

        int m = str1.size(), n = str2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        string ans = "";

        int i = m, j = n;

        while (i >= 1 && j >= 1)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                ans = str1[i - 1] + ans;
                i--;
                j--;
            }
            else
            {
                if (dp[i][j - 1] > dp[i - 1][j])
                {
                    ans = str2[j - 1] + ans;
                    j--;
                }
                else
                {
                    ans = str1[i - 1] + ans;
                    i--;
                }
            }
        }

        while (j >= 1)
        {
            ans = str2[j - 1] + ans;
            j--;
        }

        while (i >= 1)
        {
            ans = str1[i - 1] + ans;
            i--;
        }

        return ans;
    }
};