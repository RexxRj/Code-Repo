class Solution
{

public:
    bool canPartition(vector<int> &nums)
    {

        int sum = 0, n = nums.size();
        ;

        for (auto &x : nums)
            sum += x;

        if (sum & 1)
            return false;

        sum = sum / 2;

        vector<vector<bool>> dp(2, vector<bool>(sum + 1));

        for (int i = 0; i <= sum; i++)
            dp[n % 2][i] = i == 0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (nums[i] > j)
                    dp[i % 2][j] = dp[(i + 1) % 2][j];
                else
                    dp[i % 2][j] = dp[(i + 1) % 2][j] || dp[(i + 1) % 2][j - nums[i]];
            }
        }

        return dp[0][sum];
    }
};