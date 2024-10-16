class Solution
{
public:
    string longestPalindrome(string s)
    {

        int n = s.length();

        vector<vector<int>> v(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            v[i][i] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (s[j - i] == s[j])
                {
                    if (j - i + 1 > j - 1 || v[j - i + 1][j - 1] == 1)
                        v[j - i][j] = 1;
                }
            }
        }

        /*for(int i=0; i<n; i++)
         {
             for(int j = 0; j<n; j++)
             cout<<v[i][j]<<" ";
             cout<<endl;
         }*/

        int start = 0, maxlen = 1;

        for (int j = n - 1; j >= 0; j--)
        {
            for (int i = 0; i < j; i++)
            {
                if (v[i][j] == 1 && i != j && maxlen < j - i + 1)
                {
                    start = i;
                    maxlen = j - i + 1;
                    break;
                }
            }
        }

        // cout<<start<<" "<<maxlen<<endl;

        return s.substr(start, maxlen);
    }
};