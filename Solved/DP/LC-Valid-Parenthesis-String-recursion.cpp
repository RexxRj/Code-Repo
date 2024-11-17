class Solution
{

    bool solve(string &s, int ind, int cnt, vector<vector<int>> &dp)
    {
        if (cnt < 0)
            return false;

        if (ind == s.size())
            return cnt == 0;

        if (dp[ind][cnt] != -1)
            return dp[ind][cnt] == 1;

        if (s[ind] == '(')
            return dp[ind][cnt] = solve(s, ind + 1, cnt + 1, dp);
        if (s[ind] == ')')
            return dp[ind][cnt] = solve(s, ind + 1, cnt - 1, dp);

        return dp[ind][cnt] = solve(s, ind + 1, cnt + 1, dp) || solve(s, ind + 1, cnt - 1, dp) || solve(s, ind + 1, cnt, dp);
    }

public:
    bool checkValidString(string s)
    {

        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(s, 0, 0, dp);
    }
};