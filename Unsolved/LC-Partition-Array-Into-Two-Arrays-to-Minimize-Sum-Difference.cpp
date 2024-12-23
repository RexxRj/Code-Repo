class Solution
{

    int solve(int i, long sum, int cnt, int &n, int &total, vector<int> &nums, vector<unordered_map<int, long>> &dp)
    {
        if (cnt == n)
            return abs(total - 2 * sum);

        if (i == 2 * n)
            return 1e9;

        if (dp[i].find(sum) != dp[i].end())
            return dp[i][sum];

        return dp[i][sum] = min(solve(i + 1, sum, cnt, n, total, nums, dp), solve(i + 1, nums[i] + sum, cnt + 1, n, total, nums, dp));
    }

public:
    int minimumDifference(vector<int> &nums)
    {

        int n = nums.size() / 2;
        int total = 0;

        for (auto x : nums)
            total += x;

        vector<unordered_map<int, long>> dp(2 * n);

        return solve(0, 0, 0, n, total, nums, dp);
    }
};