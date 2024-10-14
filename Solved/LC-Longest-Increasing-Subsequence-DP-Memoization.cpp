class Solution
{
    int LIS(int ind, int prevInd, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (ind == nums.size())
            return 0;

        if (dp[ind][prevInd + 1] != -1)
            return dp[ind][prevInd + 1];

        int len = LIS(ind + 1, prevInd, nums, dp);

        if (prevInd == -1 || nums[ind] > nums[prevInd])
            len = max(len, 1 + LIS(ind + 1, ind, nums, dp));

        return dp[ind][prevInd + 1] = len;
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return LIS(0, -1, nums, dp);
    }
};