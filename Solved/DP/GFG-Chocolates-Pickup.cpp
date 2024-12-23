//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

    int calc(int i, int j1, int j2, int &n, int &m, vector<vector<int>> &grid,
             vector<vector<vector<int>>> &dp)
    {
        if (i == n || j1 < 0 || j2 < 0 || j1 == m || j2 == m)
            return -1e9;

        if (i == n - 1)
        {
            if (j1 == j2)
                return grid[i][j2];
            else
                return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int res = -1e9;

        for (int k1 = -1; k1 < 2; k1++)
        {
            for (int k2 = -1; k2 < 2; k2++)
            {
                int val = calc(i + 1, j1 + k1, j2 + k2, n, m, grid, dp);
                if (j1 != j2)
                    res = max(res, grid[i][j1] + grid[i][j2] + val);
                else
                    res = max(res, grid[i][j1] + val);
            }
        }

        return dp[i][j1][j2] = res;
    }

public:
    int solve(int n, int m, vector<vector<int>> &grid)
    {
        // code here

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return calc(0, 0, m - 1, n, m, grid, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            for (int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends