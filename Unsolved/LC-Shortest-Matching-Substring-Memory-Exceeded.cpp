class Solution
{

    int solve(int i, int j, string &s, string &p, string res, vector<vector<int>> &dp)
    {
        if (j == p.size())
        {
            return res.size();
        }

        if (i == s.size())
        {

            while (j < p.size() && p[j] == '*')
                j++;
            if (j == p.size())
                return res.size();
            else
                return 1e9;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans1 = solve(i + 1, 0, s, p, "", dp), ans2 = 1e9, ans3 = 1e9;

        if (s[i] == p[j])
            ans2 = solve(i + 1, j + 1, s, p, res + s[i], dp);
        else if (p[j] == '*')
        {
            // cout<<j<<" "<<res<<endl;
            ans3 = solve(i, j + 1, s, p, res, dp);
            for (int ind = i; ind < s.size(); ind++)
            {
                res = res + s[ind];
                ans3 = min(ans3, solve(ind + 1, j + 1, s, p, res, dp));
            }
        }

        return dp[i][j] = min(ans1, min(ans2, ans3));
    }

public:
    int shortestMatchingSubstring(string s, string p)
    {

        int m = s.size(), n = p.size();

        vector<vector<int>> dp(m + 1, vector<int>(n, -1));

        int ans = solve(0, 0, s, p, "", dp);

        return ans == 1e9 ? -1 : ans;
    }
};