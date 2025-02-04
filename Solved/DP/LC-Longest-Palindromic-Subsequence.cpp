// Same as Longest common subsequence, reverse the string and find ans.

class Solution
{

    /*int solve(int i, int j, string& s,vector<vector<int>>& dp)
    {
        if(i == s.size() || j<0)
        return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = max(solve(i+1,j,s,dp),solve(i,j-1,s,dp));

        if(s[i] == s[j])
        ans = max(ans,1 + solve(i+1,j-1,s,dp));

        return dp[i][j] = ans;
    }*/

public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        vector<int> prev(n + 1, 0), cur(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                int ans = max(prev[j], cur[j - 1]);

                if (s[i] == s[j - 1])
                    ans = max(ans, 1 + prev[j - 1]);

                cur[j] = ans;
            }

            prev = cur;
        }

        return prev[n];
    }
};