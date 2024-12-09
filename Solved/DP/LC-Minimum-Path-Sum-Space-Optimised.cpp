class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n+1,0);
        dp[n-1] = grid[m-1][n-1];


        for(int i = m-1; i>=0; i--)
        {
            for(int j = n-1; j>=0; j--)
            {
                if(i == (m-1) && j == (n-1)) continue;

                if(i == m-1)
                dp[j] = grid[i][j] + dp[j+1];

                else if(j == n-1)
                dp[j] = grid[i][j] + dp[j];

                else
                dp[j] = grid[i][j] + min( dp[j], dp[j+1]);
            }
        }

        return dp[0];
    }
};