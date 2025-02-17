class Solution
{
public:
    int minDistance(string word1, string word2)
    {

        int m = word1.size(), n = word2.size();

        vector<int> prev(n + 1, 0), cur(n + 1, 0);

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int ans = max(cur[j - 1], prev[j]);

                if (word1[i - 1] == word2[j - 1])
                    ans = 1 + prev[j - 1];

                cur[j] = ans;
            }

            prev = cur;
        }

        return m - prev[n] + n - prev[n];
    }
};