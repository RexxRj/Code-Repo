class Solution
{

    /*  int solve(int i,int j, string& s, string& t,vector<vector<int>>& dp)
      {
          if(j<0)
          return 1;

          if(i<0)
          return 0;

          if(dp[i][j] != -1)
          return dp[i][j];

          int ntake = solve(i-1,j,s,t,dp);
          int take = 0;
          if(s[i] == t[j])
          take = solve(i-1,j-1,s,t,dp);

          return dp[i][j] = ntake+take;
      }   */

public:
    int numDistinct(string s, string t)
    {

        int m = s.size(), n = t.size();
        // vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        vector<int> prev(n + 1, 0), cur(n + 1, 0);

        prev[0] = 1, cur[0] = 1;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                long long ans = prev[j];

                if (s[i - 1] == t[j - 1])
                    ans += prev[j - 1];

                cur[j] = ans;
            }
            prev = cur;
        }

        return prev[n];
    }
};