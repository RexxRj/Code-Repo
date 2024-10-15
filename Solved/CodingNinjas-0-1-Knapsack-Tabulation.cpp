int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    // Write your code here
    vector<vector<int>> v(2, vector<int>(w + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (j - weights[i - 1] < 0)
                v[i % 2][j] = v[(i - 1) % 2][j];
            else
                v[i % 2][j] = max(values[i - 1] + v[(i - 1) % 2][j - weights[i - 1]], v[(i - 1) % 2][j]);
        }
    }

    return v[n % 2][w];
}