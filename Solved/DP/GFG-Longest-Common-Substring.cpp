//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

    /* int solve(int i, int j, string& s1, string& s2,vector<vector<int>>& dp)
     {
         if(i<0 || j<0)
         return 0;

         if(dp[i][j] != -1) return dp[i][j];

         int ans = max(solve(i,j-1,s1,s2,dp),solve(i-1,j,s1,s2,dp));

         int len = 0;

         int ind1 = i, ind2 = j;

         while(ind1>=0 && ind2>=0 && s1[ind1] == s2[ind2])
         {
             len++;
             ind1--;
             ind2--;
         }

         return dp[i][j] = max(ans,len);
     }
     */
public:
    int longestCommonSubstr(string &s1, string &s2)
    {
        // your code here
        // vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,0));
        vector<int> prev(s2.size() + 1, 0), cur(s2.size() + 1, 0);

        for (int i = 1; i <= s1.size(); i++)
        {
            for (int j = 1; j <= s2.size(); j++)
            {
                int ans = max(cur[j - 1], prev[j]);
                int len = 0;

                int ind1 = i - 1, ind2 = j - 1;

                while (ind1 >= 0 && ind2 >= 0 && s1[ind1] == s2[ind2])
                {
                    len++;
                    ind1--;
                    ind2--;
                }

                cur[j] = max(ans, len);
            }

            prev = cur;
        }

        return prev[s2.size()];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends