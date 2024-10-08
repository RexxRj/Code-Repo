//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.

    void solve(int V, vector<int> adj[], vector<int> &visited, int node, vector<int> &ans)
    {
        if (visited[node] == 1 || node >= V)
            return;

        ans.push_back(node);
        visited[node] = 1;

        for (int i = 0; i < adj[node].size(); i++)
        {
            solve(V, adj, visited, adj[node][i], ans);
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> visited(V, 0);
        vector<int> ans;

        solve(V, adj, visited, 0, ans);
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
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends