class Solution
{

private:
    void dfs(int node, vector<vector<bool>> &graph, vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;

        for (int i = 0; i < 26; i++)
        {
            if (!vis[i] && graph[node][i])
                dfs(i, graph, vis, st);
        }

        st.push(node);
    }

    void dfs2(int node, vector<vector<bool>> &graph, vector<int> &vis, vector<int> &temp)
    {
        vis[node] = 1;

        for (int i = 0; i < 26; i++)
        {
            if (!vis[i] && graph[node][i])
                dfs2(i, graph, vis, temp);
        }

        temp.push_back(node);
    }

public:
    vector<string> maxNumOfSubstrings(string s)
    {

        vector<vector<bool>> graph(26, vector<bool>(26, false));
        vector<vector<bool>> grev(26, vector<bool>(26, false));

        vector<int> beg(26, -1);
        vector<int> end(26, -1);

        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            if (beg[s[i] - 'a'] == -1)
                beg[s[i] - 'a'] = i;
            end[s[i] - 'a'] = i;
        }

        for (int ch = 0; ch < 26; ch++)
        {
            if (beg[ch] != -1)
            {
                for (int i = beg[ch]; i <= end[ch]; i++)
                {
                    graph[ch][s[i] - 'a'] = true;
                    grev[s[i] - 'a'][ch] = true;
                }
            }
        }

        vector<int> vis(26, 0);
        stack<int> st;

        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (!vis[i] && graph[i][j])
                    dfs(i, graph, vis, st);
            }
        }

        vector<vector<int>> scc;
        vis.assign(26, 0);

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (!vis[node])
            {
                vector<int> temp;
                dfs2(node, grev, vis, temp);
                scc.push_back(temp);
            }
        }

        vector<int> sccIndex(26, -1);

        for (int i = 0; i < scc.size(); i++)
        {
            for (auto &x : scc[i])
                sccIndex[x] = i;
        }

        vector<int> degree(scc.size(), 0);

        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (graph[i][j])
                {
                    if (sccIndex[i] != sccIndex[j])
                        degree[sccIndex[i]]++;
                }
            }
        }

        vector<string> ans;

        for (int i = 0; i < scc.size(); i++)
        {
            if (degree[i] == 0)
            {
                int left = INT_MAX, right = INT_MIN;
                for (auto &x : scc[i])
                {
                    left = min(left, beg[x]);
                    right = max(right, end[x]);
                }

                ans.push_back(s.substr(left, right - left + 1));
            }
        }

        return ans;
    }
};