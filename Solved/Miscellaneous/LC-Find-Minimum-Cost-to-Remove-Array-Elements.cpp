class Solution
{

    int solve(int i, int prev, vector<int> &nums, vector<vector<int>> &dp)
    {
        // cout<<"i: "<<i<<endl;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);

        if (i >= nums.size())
        {
            // cout<<"numsprev: "<<nums[prev]<<endl;
            return nums[prev];
        }

        if (i + 1 >= nums.size())
            return max(nums[prev], nums[i]);

        if (prev != -1 && dp[i][prev] != -1)
            return dp[i][prev];

        int ans = INT_MAX;
        int first, second, third;

        if (prev == -1)
        {
            first = i;
            second = i + 1;
            third = i + 2;
        }
        else
        {
            first = prev;
            second = i;
            third = i + 1;
        }

        ans = min(ans, max(nums[first], nums[second]) + solve(third + 1, third, nums, dp));
        // cout<<third<<" "<<ans<<endl;
        ans = min(ans, max(nums[first], nums[third]) + solve(third + 1, second, nums, dp));
        // cout<<second<<" "<<ans<<endl;
        ans = min(ans, max(nums[second], nums[third]) + solve(third + 1, first, nums, dp));
        // cout<<first<<" "<<ans<<endl;

        if (prev == -1)
            return ans;

        return dp[i][prev] = ans;
    }

public:
    int minCost(vector<int> &nums)
    {

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, -1, nums, dp);
    }
};