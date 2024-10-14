//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet
{

    vector<int> parent, size;

public:
    DisjointSet(int n)
    {

        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node)
    {

        if (parent[node] == node)
            return node;
        else
            return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {

        int ult_u = findUPar(u);
        int ult_v = findUPar(v);

        if (ult_u == ult_v)
            return;
        else if (size[ult_u] < size[ult_v])
        {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        else
        {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
                pq.push({it[1], {i, it[0]}});
        }

        int ans = 0;

        DisjointSet ds(V);

        while (!pq.empty())
        {

            int wt = pq.top().first;
            int node = pq.top().second.first;
            int adjNode = pq.top().second.second;
            pq.pop();

            if (ds.findUPar(node) != ds.findUPar(adjNode))
            {
                ans += wt;
                ds.unionBySize(node, adjNode);
            }
        }

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
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends