class Solution
{

    bool findkey(vector<string> &w, string s)
    {
        auto it = find(w.begin(), w.end(), s);

        if (it != w.end())
            return true;
        return false;
    }

    bool solve(int ind, int start, string &s, vector<string> &wordDict, vector<vector<int>> &dp)
    {
        if (ind == s.size())
            return findkey(wordDict, s.substr(start, ind - start));

        if (dp[ind][start] != -1)
            return dp[ind][start] == 0 ? false : true;
        bool ntake = solve(ind + 1, start, s, wordDict, dp);

        if (findkey(wordDict, s.substr(start, ind - start + 1)))
            ntake = ntake || solve(ind + 1, ind + 1, s, wordDict, dp);
        dp[ind][start] = ntake == false ? 0 : 1;
        return ntake;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {

        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, 0, s, wordDict, dp);
    }
};