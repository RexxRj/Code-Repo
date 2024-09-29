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
    bool solve(TreeNode *root, int &k, unordered_set<int> &v, bool &ans)
    {
        if (root == NULL || ans == true)
            return ans;

        if (v.find(root->val) != v.end())
            return ans = true;
        v.insert(k - root->val);

        return ans = solve(root->left, k, v, ans) || solve(root->right, k, v, ans);
    }

    bool findTarget(TreeNode *root, int k)
    {

        bool ans = false;
        unordered_set<int> v;
        return solve(root, k, v, ans);
    }
};
