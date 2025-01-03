//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    int solve(string &s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        vector<int> last(26, -1);

        for (int i = 1; i <= n; i++)
        {
            int j = last[s[i - 1] - 'a']; // last occurence of the character

            int val = 0;

            if (j != -1)
                val = dp[j - 1]; // if repeated character, remove the duplicates based on
            // previous index count before this repeated character.

            dp[i] = 2 * dp[i - 1] - val;

            last[s[i - 1] - 'a'] = i; // update last character
        }

        return dp[n];
    }

public:
    string betterString(string str1, string str2)
    {
        // code here

        int cnt1 = solve(str1);
        int cnt2 = solve(str2);

        return cnt1 >= cnt2 ? str1 : str2;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";

        cout << "~" << "\n";
    }
}

// } Driver Code Ends