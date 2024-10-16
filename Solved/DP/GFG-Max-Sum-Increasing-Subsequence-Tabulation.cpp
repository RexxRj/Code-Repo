// Bottom Up Tabulation
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int maxSumIS(int arr[], int n)
    {
        // Your code goes here
        vector<vector<int>> dp(2, vector<int>(n + 2, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n + 1; j++)
            {
                int LIS = dp[(i - 1) % 2][j];
                if (j == n + 1 || arr[i - 1] < arr[j - 1])
                    LIS = max(LIS, arr[i - 1] + dp[(i - 1) % 2][i]);

                dp[i % 2][j] = LIS;
            }
        }

        return dp[n % 2][n + 1];
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