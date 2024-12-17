//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> replaceWithRank(vector<int> &arr, int N)
    {

        priority_queue<int> pq;

        for (auto &x : arr)
        {
            pq.push(-x);
        }

        int rank = 0;
        vector<int> rankArr;
        unordered_map<int, int> m;
        int prevEl = 0;

        while (!pq.empty())
        {
            int el = -pq.top();
            pq.pop();
            if (el != prevEl)
                rank++;
            m[el] = rank;

            prevEl = el;
        }

        for (auto &x : arr)
        {
            rankArr.push_back(m[x]);
        }

        return rankArr;
    }
};

//{ Driver Code Starts.
int main()
{
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--)
    {
        // Input

        int n;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec, n);
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;

        // cout << "~\n";

        cout << "~" << "\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends