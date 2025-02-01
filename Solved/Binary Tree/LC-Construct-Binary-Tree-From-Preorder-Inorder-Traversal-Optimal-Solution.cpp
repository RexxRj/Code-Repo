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
    TreeNode *solve(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &m)
    {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        TreeNode *root = new TreeNode(preorder[preStart]);

        int rootIndex = m[root->val];

        int leftLen = rootIndex - inStart;

        root->left = solve(preorder, preStart + 1, preStart + leftLen, inorder, inStart, rootIndex - 1, m);

        root->right = solve(preorder, preStart + leftLen + 1, preEnd, inorder, rootIndex + 1, inEnd, m);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        unordered_map<int, int> m;

        for (int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;

        return solve(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, m);
    }
};