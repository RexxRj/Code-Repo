//{ Driver Code Starts
#include <iostream>
#include <vector>
using namespace std;

// } Driver Code Ends
class Solution
{

    int solve(int ind, int act, vector<vector<int>> &arr, int n, vector<vector<int>> &dp)
    {
        // cout << ind << " " << act << endl;
        if (ind == n)
        {
            // cout << "end" << endl;
            return 0;
        }

        if (act != -1 && dp[ind][act] != -1)
        {
            // cout << "dp: " << dp[ind][act] << endl;
            return dp[ind][act];
        }

        int points = INT_MIN;

        for (int i = 0; i < 3; i++)
        {
            if (i != act)
                points = max(points, arr[ind][i] + solve(ind + 1, i, arr, n, dp));
        }

        // cout << "points: " << points << endl;
        if (act != -1)
            return dp[ind][act] = points;

        return points;
    }

public:
    int maximumPoints(vector<vector<int>> &arr, int n)
    {
        // Code here
        vector<vector<int>> dp(n, vector<int>(3, -1));

        return solve(0, -1, arr, n, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        int n;
        // cin >> n;
        n = 10;
        vector<vector<int>> arr;
        arr = {
            {7, 6, 1},
            {3, 9, 7},
            {1, 3, 5},
            {9, 7, 6},
            {1, 10, 1},
            {1, 7, 2},
            {4, 9, 10},
            {4, 5, 5},
            {7, 1, 7},
            {7, 2, 9},
        };
        // for (int i = 0; i < n; ++i)
        // {
        //     vector<int> temp;
        //     for (int j = 0; j < 3; ++j)
        //     {
        //         int x;
        //         cin >> x;
        //         temp.push_back(x);
        //     }
        //     arr.push_back(temp);
        // }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends