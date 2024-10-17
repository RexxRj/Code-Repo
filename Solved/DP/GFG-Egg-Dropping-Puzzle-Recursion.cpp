//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

    int solve(int eggs, int floor, vector<vector<int>> &dp)
    {
        if (eggs == 1 || floor <= 1)
            return floor;

        if (dp[eggs][floor] != -1)
            return dp[eggs][floor];

        int ans = INT_MAX;

        for (int k = 1; k <= floor; k++)
        {
            int res = 1 + max(solve(eggs - 1, k - 1, dp), solve(eggs, floor - k, dp));
            ans = min(ans, res);
        }

        return dp[eggs][floor] = ans;
    }

public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int k)
    {
        // your code here
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

        return solve(n, k, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        // calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends