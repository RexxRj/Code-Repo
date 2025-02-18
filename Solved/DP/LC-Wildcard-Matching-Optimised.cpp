// solve(i,j-1,s,p,dp) || solve(i-1,j,s,p,dp); check for empty string or check * with next string. This was the trick!!

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


         if(s[i] == p[j] || p[j] == '?')
             return dp[i][j] = solve(i-1,j-1,s,p,dp);
         else if(p[j] == '*')
         {
             return dp[i][j] = solve(i,j-1,s,p,dp) || solve(i-1,j,s,p,dp);
         }

         return false;
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
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                else
                    dp[i][j] = 0;
            }
        }

        return dp[m][n];

        // return solve(m-1,n-1,s,p,dp);
    }
};