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
    vector<int> solve(TreeNode *root, bool &ans)
    {
        if (root == NULL || ans == false)
            return {};

        vector<int> ls = solve(root->left, ans);
        vector<int> rs = solve(root->right, ans);

        if ((ls.size() > 0 && ls[1] >= root->val) || (rs.size() > 0 && rs[0] <= root->val))
            ans = false;

        int minn = root->val, maxx = root->val;

        if (ls.size() > 0)
        {
            minn = min(minn, ls[0]);
            maxx = max(maxx, ls[1]);
        }
        if (rs.size() > 0)
        {
            minn = min(minn, rs[0]);
            maxx = max(maxx, rs[1]);
        }

        return {minn, maxx};
    }

    bool isValidBST(TreeNode *root)
    {

        bool ans = true;

        solve(root, ans);

        return ans;
    }
};