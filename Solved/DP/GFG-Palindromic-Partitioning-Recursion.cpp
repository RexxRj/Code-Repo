//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    bool check(int i, int j, string &str)
    {
        while (i <= j)
        {
            if (str[i] != str[j])
                return false;
            i++;
            j--;
        }

        return true;
    }

    int solve(int start, int end, string &str, vector<vector<int>> &dp)
    {
        if (start >= end || check(start, end, str))
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];

        if (check(start, end, str))
            dp[start][end] = 0;

        int ans = 1e9;

        for (int k = start; k < end; k++)
        {
            if (check(start, k, str))
                ans = min(ans, 1 + solve(start, k, str, dp) + solve(k + 1, end, str, dp));
        }

        return dp[start][end] = ans;
    }

public:
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, str.length() - 1, str, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}
// } Driver Code Ends