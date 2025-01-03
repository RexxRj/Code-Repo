class Solution
{

    void solve(int open, int close, string res, vector<string> &ans)
    {
        if (open == 0 && close == 0)
        {
            ans.push_back(res);
            return;
        }

        if (open > 0)
            solve(open - 1, close, res + '(', ans);
        if (close > 0 && close > open)
            solve(open, close - 1, res + ')', ans);
    }

public:
    vector<string> generateParenthesis(int n)
    {

        vector<string> ans;

        solve(n, n, "", ans);

        return ans;
    }
};