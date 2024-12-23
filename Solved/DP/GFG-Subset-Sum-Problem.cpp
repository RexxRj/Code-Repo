//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{

    bool solve(int i, vector<int> &arr, int target, vector<vector<int>> &dp)
    {

        if (target == 0)
            return true;

        if (i == arr.size() || target < 0)
            return false;

        if (dp[i][target] != -1)
            return dp[i][target];

        return dp[i][target] = solve(i + 1, arr, target, dp) || solve(i + 1, arr, target - arr[i], dp);
    }

public:
    bool isSubsetSum(vector<int> &arr, int target)
    {
        // code here

        vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));

        return solve(0, arr, target, dp);
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends