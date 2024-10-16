class Solution
{
    int LCS(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (ind1 < 0 || ind2 < 0)
            return 0;

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (s1[ind1] == s2[ind2])
            return dp[ind1][ind2] = 1 + LCS(ind1 - 1, ind2 - 1, s1, s2, dp);

        return dp[ind1][ind2] = max(LCS(ind1 - 1, ind2, s1, s2, dp), LCS(ind1, ind2 - 1, s1, s2, dp));
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {

        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));

        return LCS(text1.size() - 1, text2.size() - 1, text1, text2, dp);
    }
};