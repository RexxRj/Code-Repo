class Solution
{
    bool bfs(vector<vector<int>> &graph, vector<int> &vis, int node)
    {
        queue<int> q;

        q.push(node);
        vis[node] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            int part = vis[node];
            part = part == 0 ? 1 : 0;

            for (auto &x : graph[node])
            {
                if (vis[x] == -1)
                {
                    q.push(x);
                    vis[x] = part;
                }
                else if (vis[x] == vis[node])
                    return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {

        vector<int> vis(graph.size(), -1);

        for (int i = 0; i < graph.size(); i++)
        {
            if (vis[i] == -1 && !bfs(graph, vis, i))
                return false;
        }

        return true;
    }
};