class Solution
{

    bool solve(int i, vector<int> &nums, int target, vector<vector<int>> &dp)
    {
        if (i == nums.size())
            return target == 0;

        if (dp[i][target] != -1)
            return dp[i][target];

        if (nums[i] > target)
            return dp[i][target] = solve(i + 1, nums, target, dp);

        return dp[i][target] = solve(i + 1, nums, target, dp) || solve(i + 1, nums, target - nums[i], dp);
    }

public:
    bool canPartition(vector<int> &nums)
    {

        int sum = 0;

        for (auto &x : nums)
            sum += x;

        if (sum & 1)
            return false;

        vector<vector<int>> dp(nums.size(), vector<int>(sum / 2 + 1, -1));

        return solve(0, nums, sum / 2, dp);
    }
};