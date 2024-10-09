class Solution
{

    bool dfs(int node, vector<vector<int>> &graph, vector<int> &vis, int part)
    {
        vis[node] = part;
        int part2 = part == 0 ? 1 : 0;

        for (auto &x : graph[node])
        {
            if (vis[x] == -1 && !dfs(x, graph, vis, part2))
                return false;
            else if (vis[x] == part)
                return false;
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {

        vector<int> vis(graph.size(), -1);

        for (int i = 0; i < graph.size(); i++)
        {
            if (vis[i] == -1 && !dfs(i, graph, vis, 0))
                return false;
        }

        return true;
    }
};