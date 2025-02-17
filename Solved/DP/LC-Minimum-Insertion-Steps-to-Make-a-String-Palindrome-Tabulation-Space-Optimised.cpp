class Solution
{
public:
    int minInsertions(string s)
    {

        int n = s.size();
        vector<int> prev(n + 1, 0), cur(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int ans = max(cur[j - 1], prev[j]);

                if (s[i - 1] == s[n - j])
                    ans = 1 + prev[j - 1];

                cur[j] = ans;
            }

            prev = cur;
        }

        return n - prev[n];
    }
};