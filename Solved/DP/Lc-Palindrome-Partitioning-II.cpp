class Solution
{

    bool check(int start, int end, string &s)
    {
        int i = start, j = end;

        while (i <= j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }

    /*int solve(int i, string& s, vector<int>& dp)
    {
        if(i == s.length())
        return 0;

        if(check(i,s.length()-1,s))
        return 0;

        if(dp[i] != -1)
        return dp[i];

        int ans = 1e9;

        for(int k = i; k<s.length(); k++)
        {
            if(check(i,k,s))
            ans = min(ans, 1 + solve(k+1,s,dp));
        }

        return dp[i] = ans;
    }*/

public:
    int minCut(string s)
    {

        int n = s.length();
        vector<int> dp(n, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            if (check(i, s.length() - 1, s))
                dp[i] = 0;
            else
            {
                int ans = 1e9;

                for (int k = i; k < s.length(); k++)
                {
                    if (check(i, k, s))
                        ans = min(ans, 1 + dp[k + 1]);
                }

                dp[i] = ans;
            }
        }

        return dp[0];

        // return solve(0,s,dp);
    }
};