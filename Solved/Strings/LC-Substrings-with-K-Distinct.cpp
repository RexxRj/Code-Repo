//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{

    int count(string &s, int k) // function to count substr atleast k characters
    {
        int i = 0, j = 0, cnt = 0, n = s.size();
        unordered_map<char, int> m;

        while (j < n)
        {
            m[s[j]]++;

            while (i <= j && m.size() == k)
            {
                cnt += n - j; // total substr atleast k characters
                m[s[i]]--;

                if (m[s[i]] == 0)
                    m.erase(s[i]);
                i++;
            }

            j++;
        }

        return cnt;
    }

public:
    int countSubstr(string &s, int k)
    {
        // code here.

        return count(s, k) - count(s, k + 1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.countSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends