class Solution
{

    /* int solve(int i, int j, string& s, string& t,vector<vector<int>>& dp)
     {
         if(i<0 && j<0)
         return 0;

         if(dp[i+1][j+1] != -1)
         return dp[i+1][j+1];

         int ans = 1e9;

         if(i>=0 && j>=0)
         {
             if(s[i] == t[j])
             ans = min(ans,solve(i-1,j-1,s,t,dp));
             else
             ans = min(ans,1 + solve(i-1,j-1,s,t,dp)); //replace
         }

         if(i>=0)
         ans = min(ans,1 + solve(i-1,j,s,t,dp)); //deletion

         if(j>=0)
         ans = min(ans,1 + solve(i,j-1,s,t,dp)); //insertion

         return dp[i+1][j+1] = ans;


     }*/

public:
    int minDistance(string word1, string word2)
    {

        int m = word1.size(), n = word2.size();
        // vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        vector<int> prev(n + 1, 0), cur(n + 1, 0);

        for (int j = 0; j <= n; j++)
            prev[j] = j;

        for (int i = 1; i <= m; i++)
        {
            cur[0] = i;
            for (int j = 1; j <= n; j++)
            {
                int ans = 1e9;

                if (word1[i - 1] == word2[j - 1])
                    ans = min(ans, prev[j - 1]);
                else
                    ans = min(ans, 1 + prev[j - 1]); // replace

                ans = min(ans, 1 + prev[j]); // deletion

                ans = min(ans, 1 + cur[j - 1]); // insertion

                cur[j] = ans;
            }
            prev = cur;
        }

        return prev[n];
    }
};