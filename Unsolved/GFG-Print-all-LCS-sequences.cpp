//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

    set<string> LCS(int m, int n, string &s, string &t, vector<vector<int>> &dp)
    {
        if (m == 0 || n == 0)
            return {""};

        if (s[m - 1] == t[n - 1])
        {
            set<string> res = LCS(m - 1, n - 1, s, t, dp);

            set<string> res2;

            for (auto &x : res)
                res2.insert(x + s[m - 1]);

            return res2;
        }

        if (dp[m - 1][n] > dp[m][n - 1])
        {
            return LCS(m - 1, n, s, t, dp);
        }

        if (dp[m][n - 1] > dp[m - 1][n])
        {
            return LCS(m, n - 1, s, t, dp);
        }

        set<string> left, top;

        left = LCS(m, n - 1, s, t, dp);
        top = LCS(m - 1, n, s, t, dp);

        for (auto &x : left)
            top.insert(x);

        return top;
    }

public:
    vector<string> all_longest_common_subsequences(string s, string t)
    {
        // Code here
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                int val = max(dp[i][j - 1], dp[i - 1][j]);

                if (s[i - 1] == t[j - 1])
                    val = max(val, 1 + dp[i - 1][j - 1]);

                dp[i][j] = val;
            }
        }

        set<string> st;

        st = LCS(s.size(), t.size(), s, t, dp);

        vector<string> ans;

        for (auto &x : st)
            ans.push_back(x);

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends