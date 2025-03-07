class Solution
{

    /*int solve(int i,int& n, vector<int>& arr, int& k,vector<int>& dp)
    {
        if(i == n)
        return 0;
        if(dp[i] != -1)
        return dp[i];

        int ans = 0, maxEl = INT_MIN;

        for(int j = i; j<min(n, i+k); j++)
        {
            maxEl = max(maxEl, arr[j]);
            ans = max(ans, maxEl*(j-i+1) + solve(j+1,n,arr,k,dp)   );
        }

        return dp[i] = ans;
    }*/

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        int ans, maxEl;

        for (int i = n - 1; i >= 0; i--)
        {
            ans = 0, maxEl = INT_MIN;

            for (int j = i; j < min(n, i + k); j++)
            {
                maxEl = max(maxEl, arr[j]);
                ans = max(ans, maxEl * (j - i + 1) + dp[j + 1]);
            }

            dp[i] = ans;
        }
        return dp[0];
        // return solve(0,n,arr,k,dp);
    }
};