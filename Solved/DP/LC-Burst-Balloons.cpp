class Solution
{

    /*int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(i>j)
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        int ans = 0;
        for(int k = i; k<=j; k++)
        {
            ans = max(ans,
            nums[i-1]*nums[k]*nums[j+1] + solve(i,k-1,nums,dp) + solve(k+1,j,nums,dp));
        }

        return dp[i][j] = ans;
    }*/

public:
    int maxCoins(vector<int> &nums)
    {

        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i > 0; i--)
        {
            for (int j = i; j <= n; j++)
            {
                int ans = 0;
                for (int k = i; k <= j; k++)
                {
                    ans = max(ans,
                              nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j]);
                }
                dp[i][j] = ans;
            }
        }

        return dp[1][n];
        // return solve(1,n,nums,dp);
    }
};