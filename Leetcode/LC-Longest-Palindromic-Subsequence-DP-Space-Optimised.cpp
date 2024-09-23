class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.length();
        vector<vector<int>> v(2, vector<int>(n + 1, 0));

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (s[i - 1] == s[n - j])
                    v[i % 2][j] = v[(i - 1) % 2][j - 1] + 1;
                else
                    v[i % 2][j] = max(v[(i - 1) % 2][j], v[i % 2][j - 1]);
            }
        }

        return v[n % 2][n];
    }
};