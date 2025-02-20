//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
    {
        // Code here

        vector<int> LIS(n, 1), parent(n);
        int maxlis = 0, maxind = 0;

        for (int i = 1; i < n; i++)
        {
            parent[i] = i;
            for (int j = 0; j < i; j++)
            {
                if (arr[j] < arr[i])
                {
                    if (LIS[i] < 1 + LIS[j])
                    {
                        LIS[i] = 1 + LIS[j];
                        parent[i] = j;
                    }
                }
            }

            if (LIS[i] > maxlis)
            {
                maxlis = LIS[i];
                maxind = i;
            }
        }

        vector<int> ans;

        while (parent[maxind] != maxind)
        {
            ans.push_back(arr[maxind]);
            maxind = parent[maxind];
        }

        ans.push_back(arr[maxind]);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends