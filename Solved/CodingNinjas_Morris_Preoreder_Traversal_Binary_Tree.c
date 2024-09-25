#include <bits/stdc++.h>
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.

    vector<int> ans;

    TreeNode *cur = root;

    while (cur != NULL)
    {

        if (cur->left)
        {
            TreeNode *prev = cur->left;
            while (prev->right && prev->right != cur)
                prev = prev->right;

            if (prev->right == NULL)
            {
                ans.push_back(cur->data);
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                prev->right = NULL;
                cur = cur->right;
            }
        }
        else
        {
            ans.push_back(cur->data);
            cur = cur->right;
        }
    }

    return ans;
}