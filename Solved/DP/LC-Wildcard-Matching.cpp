// Tabulation taking more time than Recursion+Memoization

class Solution
{

    /* bool solve(int i, int j, string& s, string& p, vector<vector<int>>& dp)
     {
         if(i<0 && j<0)
         return true;

         if(j<0)
         return false;

         if(i<0)
         {
             while(j>=0 && p[j] == '*')
             j--;

             if(j<0)
             return true;
             else
             return false;
         }

         if(dp[i][j] != -1)
         return dp[i][j];

         bool ans = false;
         if(s[i] == p[j] || p[j] == '?')
         ans = ans || solve(i-1,j-1,s,p,dp);
         else if(p[j] == '*')
         {
             ans = ans || solve(i,j-1,s,p,dp);

             for(int ind = i; ind>=0; ind--)
             ans = ans || solve(ind-1,j-1,s,p,dp);
         }

         return dp[i][j] = ans == true?1:0;
     }*/

public:
    bool isMatch(string s, string p)
    {

        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        dp[0][0] = 1;

        for (int j = 1; j <= n; j++)
        {
            if (p[j - 1] != '*')
                break;

            dp[0][j] = 1;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int ans = 0;

                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    ans = ans || dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                {
                    ans = ans || dp[i][j - 1];

                    for (int ind = i; ind >= 1; ind--)
                        ans = ans || dp[ind - 1][j - 1];
                }

                dp[i][j] = ans;
            }
        }

        return dp[m][n];
    }
};