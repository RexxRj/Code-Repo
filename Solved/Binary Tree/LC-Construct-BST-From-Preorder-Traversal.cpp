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
    TreeNode *solve(vector<int> &preorder, int start, int end)
    {
        int n = preorder.size();
        if (start > end || n == 0)
            return NULL;

        TreeNode *root = new TreeNode(preorder[start]);

        int index = start;

        for (int i = start + 1; i <= end; i++)
        {
            if (preorder[i] > preorder[start])
                break;

            index = i;
        }

        root->left = solve(preorder, start + 1, index);

        root->right = solve(preorder, index + 1, end);

        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {

        return solve(preorder, 0, preorder.size() - 1);
    }
};