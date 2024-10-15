// Top Down recursion + memoization
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

    int solve(int ind, int prevInd, int arr[], int n, vector<vector<int>> &dp)
    {
        if (ind == 0)
            return 0;

        if (dp[ind][prevInd] != -1)
            return dp[ind][prevInd];

        int LIS = solve(ind - 1, prevInd, arr, n, dp);

        if (prevInd == n + 1 || arr[ind - 1] < arr[prevInd - 1])
            LIS = max(LIS, arr[ind - 1] + solve(ind - 1, ind, arr, n, dp));

        return dp[ind][prevInd] = LIS;
    }

public:
    int maxSumIS(int arr[], int n)
    {
        // Your code goes here
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, -1));
        return solve(n, n + 1, arr, n, dp);
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.maxSumIS(a, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends