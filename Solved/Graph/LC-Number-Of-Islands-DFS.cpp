class Solution
{

    void islandsearch(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis)
    {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == '0' || vis[row][col] == 1)
            return;
        vis[row][col] = 1;
        islandsearch(row - 1, col, grid, vis);
        islandsearch(row + 1, col, grid, vis);
        islandsearch(row, col - 1, grid, vis);
        islandsearch(row, col + 1, grid, vis);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {

        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int cnt = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    islandsearch(i, j, grid, visited);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};