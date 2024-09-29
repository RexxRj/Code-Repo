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
    bool check(TreeNode *root, long leftR, long rightR, bool &ans)
    {
        if (root == NULL || ans == false)
            return ans;

        if (root->val <= leftR || root->val >= rightR)
            return ans = false;

        return ans = check(root->left, leftR, root->val, ans) && check(root->right, root->val, rightR, ans);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        bool ans = true;
        return check(root, (long)INT_MIN - 1, (long)INT_MAX + 1, ans);
    }
};