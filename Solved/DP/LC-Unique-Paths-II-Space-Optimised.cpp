class Solution
{

    /*int solve(int i, int j, int& m, int& n,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(i == (m-1) && j == (n-1) && grid[i][j] != 1) return 1;

        if(i == m || j == n || grid[i][j] == 1) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = solve(i+1,j,m,n,grid,dp) + solve(i,j+1,m,n,grid,dp);
    }*/

public:
    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();
        if (grid[m - 1][n - 1] == 1)
            return 0;
        vector<long> dp(n + 1, 0);
        dp[n - 1] = 1;

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == (m - 1) && j == (n - 1))
                    continue;

                if (grid[i][j] != 1)
                    dp[j] += dp[j + 1];
                else
                    dp[j] = 0;
            }
        }

        return dp[0];
    }
};