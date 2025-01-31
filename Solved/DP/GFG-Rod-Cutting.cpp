//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    // Memoization
    int solve(int len, vector<int> &price, vector<int> &dp)
    {
        if (len == 0)
            return 0;

        if (dp[len] != -1)
            return dp[len];

        int val = 0;

        for (int i = 0; i < len; i++)
        {
            int cal = price[i] + solve(len - (i + 1), price, dp);
            val = max(val, cal);
        }

        return dp[len] = val;
    }

public:
    int cutRod(vector<int> &price)
    {
        // code here
        int len = price.size();
        vector<int> dp(len + 1, 0);
        // Tabulation
        for (int j = 1; j <= len; j++)
        {
            int val = 0;

            for (int i = 0; i < j; i++)
            {
                int cal = price[i] + dp[j - (i + 1)];
                val = max(val, cal);
            }

            dp[j] = val;
        }

        return dp[len];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends