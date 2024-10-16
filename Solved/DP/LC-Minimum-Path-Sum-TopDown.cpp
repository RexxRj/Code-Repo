class Solution
{
    int solve(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        if (row == grid.size() - 1 && col == grid[0].size() - 1)
            return grid[row][col];

        if (vis[row][col] != -1)
            return vis[row][col];

        int right = 1e9, down = 1e9;

        if (row < grid.size() - 1)
            down = solve(row + 1, col, grid, vis);

        if (col < grid[0].size() - 1)
        {
            right = solve(row, col + 1, grid, vis);
        }

        return vis[row][col] = grid[row][col] + min(down, right);
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {

        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), -1));

        return solve(0, 0, grid, vis);
    }
};