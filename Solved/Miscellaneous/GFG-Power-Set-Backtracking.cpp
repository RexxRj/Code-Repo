//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

    void solve(int ind, string res, string s, vector<string> &ans)
    {
        if (ind == s.size())
            return;

        solve(ind + 1, res, s, ans);
        res += s[ind];
        ans.push_back(res);
        solve(ind + 1, res, s, ans);
    }

public:
    vector<string> AllPossibleStrings(string s)
    {
        // Code here

        vector<string> ans;
        solve(0, "", s, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        Solution ob;
        vector<string> res = ob.AllPossibleStrings(s);
        for (auto i : res)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends