// Top Down Tabulation with Memory Optimization
class Solution
{
public:
    int minDistance(string word1, string word2)
    {

        vector<vector<int>> dp(2, vector<int>(word2.size() + 1, 0));

        for (int i = 0; i <= word2.size(); i++)
            dp[word1.size() % 2][i] = word2.size() - i;

        for (int i = word1.size() - 1; i >= 0; i--)
        {
            dp[i % 2][word2.size()] = word1.size() - i;
            for (int j = word2.size() - 1; j >= 0; j--)
            {

                if (word1[i] == word2[j])
                    dp[i % 2][j] = dp[(i + 1) % 2][j + 1];
                else
                    dp[i % 2][j] = 1 + min(dp[i % 2][j + 1], min(dp[(i + 1) % 2][j], dp[(i + 1) % 2][j + 1]));
            }
        }

        return dp[0 % 2][0];
    }
};