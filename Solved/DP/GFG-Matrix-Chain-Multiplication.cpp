//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    /*int solve(int start, int end, vector<int>& arr,vector<vector<int>>& dp)
    {
        if(end-start+1 == 2)
        return 0;

        if(dp[start][end] != -1)
        return dp[start][end];

        int ans = INT_MAX;
        for(int i = start+1; i<end; i++)
        {
            ans = min(ans,
            arr[start]*arr[i]*arr[end] + solve(start,i,arr,dp) + solve(i,end,arr,dp));
        }

        return dp[start][end] = ans;
    }*/

public:
    int matrixMultiplication(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 2; j < n; j++)
            {
                int ans = INT_MAX;

                for (int k = i + 1; k < j; k++)
                    ans = min(ans, arr[i] * arr[k] * arr[j] + dp[i][k] + dp[k][j]);

                dp[i][j] = ans;
            }
        }

        return dp[0][n - 1];
        // return solve(0,n-1,arr,dp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--)
    {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl
             << "~\n";
    }

    return 0;
}

// } Driver Code Ends