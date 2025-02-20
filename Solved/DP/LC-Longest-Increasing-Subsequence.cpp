class Solution
{

    /*int solve(int i,int j, vector<int>& nums,vector<vector<int>>& dp)
    {
        if(i == nums.size())
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        int ans = solve(i+1,j,nums,dp);

        if(j == 0 || nums[j-1]<nums[i])
        ans = max(ans,1 + solve(i+1,i+1,nums,dp));

        return dp[i][j] = ans;


    }*/

public:
    int lengthOfLIS(vector<int> &nums)
    {

        int n = nums.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        vector<int> prev(n + 1, 0), cur(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n; j >= 0; j--)
            {
                int ans = prev[j];

                if (j == 0 || nums[j - 1] < nums[i])
                    ans = max(ans, 1 + prev[i + 1]);

                cur[j] = ans;
            }
            prev = cur;
        }

        return prev[0];

        // return solve(0,0,nums,dp);
    }
};