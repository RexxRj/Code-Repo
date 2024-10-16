class Solution
{

private:
    bool cycle(int node, unordered_map<int, vector<int>> &m, vector<int> &vis, vector<int> &dfsvis)
    {
        vis[node] = 1;
        dfsvis[node] = 1;

        for (auto &x : m[node])
        {
            if (vis[x] && dfsvis[x])
                return true;
            else if (!vis[x] && cycle(x, m, vis, dfsvis))
                return true;
        }

        dfsvis[node] = 0;
        return false;
    }

public:
    bool canFinish(int n, vector<vector<int>> &arr)
    {

        unordered_map<int, vector<int>> m;

        for (auto &x : arr)
            m[x[0]].push_back(x[1]);

        vector<int> vis(n, 0);
        vector<int> dfsvis(n, 0);

        for (auto &x : m)
        {
            if (!vis[x.first] && cycle(x.first, m, vis, dfsvis))
                return false;
        }

        return true;
    }
};