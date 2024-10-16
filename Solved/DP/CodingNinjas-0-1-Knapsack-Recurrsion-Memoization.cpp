int dp(int ind, vector<vector<int>> &v, vector<int> &values, vector<int> &weights, int n, int w)
{
    if (ind == 0)
        return 0;

    if (v[ind][w] != -1)
        return v[ind][w];

    if (w - weights[ind - 1] < 0)
        return v[ind][w] = dp(ind - 1, v, values, weights, n, w);

    return v[ind][w] = max(values[ind - 1] + dp(ind - 1, v, values, weights, n, w - weights[ind - 1]),
                           dp(ind - 1, v, values, weights, n, w));
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    // Write your code here
    vector<vector<int>> v(n + 1, vector<int>(w + 1, -1));
    return dp(n, v, values, weights, n, w);
}