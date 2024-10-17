//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int kk)
    {
        // your code here
        vector<vector<int>> dp(2, vector<int>(kk + 1, -1));

        for (int f = 0; f <= kk; f++)
            dp[1][f] = f;

        for (int e = 0; e <= n; e++)
        {
            dp[e % 2][0] = 0;
            dp[e % 2][1] = 1;
        }

        for (int i = 2; i <= n; i++)
        {
            for (int j = 2; j <= kk; j++)
            {
                int ans = INT_MAX;

                for (int k = 1; k <= j; k++)
                {
                    int res = 1 + max(dp[(i - 1) % 2][k - 1], dp[i % 2][j - k]);
                    ans = min(ans, res);
                }

                dp[i % 2][j] = ans;
            }
        }

        return dp[n % 2][kk];
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