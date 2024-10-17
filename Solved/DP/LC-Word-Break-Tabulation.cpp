class Solution
{

    bool findkey(vector<string> &w, string s)
    {
        auto it = find(w.begin(), w.end(), s);

        if (it != w.end())
            return true;
        return false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {

        int n = s.size();
        vector<vector<bool>> dp(2, vector<bool>(n + 1));

        for (int j = 0; j <= n; j++)
            dp[n % 2][j] = findkey(wordDict, s.substr(j, n - j));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                bool ntake = dp[(i + 1) % 2][j];

                if (findkey(wordDict, s.substr(j, i - j + 1)))
                    ntake = ntake || dp[(i + 1) % 2][i + 1];
                dp[i % 2][j] = ntake;
            }
        }

        return dp[0][0];
    }
};