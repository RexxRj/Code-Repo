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

    void dfs2(int node, vector<vector<bool>> &graph, int sccNum, vector<int> &nodeSccNum, vector<int> &degreeSccNum)
    {
        if (nodeSccNum[node] == -1)
        {
            nodeSccNum[node] = sccNum;
            for (int i = 0; i < 26; i++)
            {
                if (graph[node][i])
                    dfs2(i, graph, sccNum, nodeSccNum, degreeSccNum);
            }
        }
        else
        {
            if (nodeSccNum[node] != sccNum)
                degreeSccNum[nodeSccNum[node]]++;
        }
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

        int sccNum = 0;
        vector<int> nodeSccNum(26, -1);
        vector<int> degreeSccNum(26, 0);

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (nodeSccNum[node] == -1)
            {
                dfs2(node, grev, sccNum, nodeSccNum, degreeSccNum);
                sccNum++;
                // cout<<node<<" ";
            }
        }

        vector<string> ans;

        while (--sccNum >= 0)
        {

            if (degreeSccNum[sccNum] == 0)
            {
                int left = INT_MAX;
                int right = INT_MIN;
                for (int i = 0; i < 26; i++)
                {
                    if (nodeSccNum[i] == sccNum)
                    {

                        left = min(left, beg[i]);
                        right = max(right, end[i]);
                    }
                }

                ans.push_back(s.substr(left, right - left + 1));
            }
        }

        return ans;
    }
};