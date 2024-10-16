/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {

        queue<pair<TreeNode *, pair<int, int>>> q;

        map<int, vector<pair<int, int>>> m;

        q.push({root, {0, 0}});

        while (!q.empty())
        {
            TreeNode *temp = q.front().first;
            int height = q.front().second.first;
            int level = q.front().second.second;

            q.pop();

            if (m.find(level) != m.end())
            {
                vector<pair<int, int>> v = m[level];
                v.push_back({height, temp->val});
                m[level] = v;
            }
            else
                m[level] = {{height, temp->val}};

            if (temp->left)
                q.push({temp->left, {height + 1, level - 1}});
            if (temp->right)
                q.push({temp->right, {height + 1, level + 1}});
        }

        vector<vector<int>> ans;

        for (auto &x : m)
        {
            vector<pair<int, int>> v = x.second;

            sort(v.begin(), v.end(), [&](pair<int, int> &a, pair<int, int> &b)
                 {
                if(a.first == b.first)
                    return a.second<b.second;
                else 
                    return a.first<b.first; });

            vector<int> res;

            for (auto &y : v)
                res.push_back(y.second);

            ans.push_back(res);
        }

        return ans;
    }
};