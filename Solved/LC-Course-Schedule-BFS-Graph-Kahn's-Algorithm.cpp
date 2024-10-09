class Solution
{
public:
    bool canFinish(int V, vector<vector<int>> &arr)
    {

        vector<vector<int>> graph(V, vector<int>());

        for (int i = 0; i < arr.size(); i++)
        {
            graph[arr[i][0]].push_back(arr[i][1]);
        }

        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++)
        {
            for (auto &x : graph[i])
            {
                indegree[x]++;
            }
        }

        queue<int> q;
        int ans = 0;

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans++;

            for (auto &x : graph[node])
            {
                indegree[x]--;
                if (indegree[x] == 0)
                    q.push(x);
            }
        }

        if (ans == V)
            return true;
        return false;
    }
};