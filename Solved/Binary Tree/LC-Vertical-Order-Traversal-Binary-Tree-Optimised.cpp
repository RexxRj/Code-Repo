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

        map<int, map<int, multiset<int>>> m;

        q.push({root, {0, 0}});

        while (!q.empty())
        {
            TreeNode *temp = q.front().first;
            int height = q.front().second.first;
            int level = q.front().second.second;

            q.pop();

            m[level][height].insert(temp->val);

            if (temp->left)
                q.push({temp->left, {height + 1, level - 1}});
            if (temp->right)
                q.push({temp->right, {height + 1, level + 1}});
        }

        vector<vector<int>> ans;

        for (auto &x : m)
        {
            vector<int> res;
            for (auto &y : x.second)
                res.insert(res.end(), y.second.begin(), y.second.end());

            ans.push_back(res);
        }

        return ans;
    }
};