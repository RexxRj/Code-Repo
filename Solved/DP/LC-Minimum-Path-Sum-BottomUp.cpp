class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {

        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> vis(2, vector<int>(n, 0));

        vis[(m - 1) % 2][n - 1] = grid[m - 1][n - 1];

        for (int i = m - 1; i >= 0; i--)
        {
            int right = 1e9, down = 1e9;
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1)
                    continue;

                if (i < grid.size() - 1)
                    down = vis[(i + 1) % 2][j];

                if (j < grid[0].size() - 1)
                    right = vis[i % 2][j + 1];

                vis[i % 2][j] = grid[i][j] + min(down, right);
            }
        }

        return vis[0][0];
    }
};