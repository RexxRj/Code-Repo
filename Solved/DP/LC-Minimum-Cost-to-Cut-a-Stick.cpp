class Solution
{

    /*int solve(int i, int j, vector<int>& cuts,vector<vector<int>>& dp)
    {
        if(i>=j-1)
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        int ans = 1e9;

        for(int k = i+1; k<j; k++)
        {
            ans = min(ans, cuts[j] - cuts[i] + solve(i,k,cuts,dp) + solve(k,j,cuts,dp));
        }

        return dp[i][j] = ans;
    }*/

public:
    int minCost(int n, vector<int> &cuts)
    {

        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int c = cuts.size();

        vector<vector<int>> dp(c, vector<int>(c, 0));

        for (int i = c - 1; i >= 0; i--)
        {
            for (int j = i + 2; j < c; j++)
            {
                int ans = 1e9;

                for (int k = i + 1; k < j; k++)
                    ans = min(ans, cuts[j] - cuts[i] + dp[i][k] + dp[k][j]);

                dp[i][j] = ans;
            }
        }

        return dp[0][c - 1];
        // return solve(0,c-1,cuts,dp);
    }
};