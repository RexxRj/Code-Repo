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
    TreeNode *buildTree(vector<int> preorder, vector<int> inorder)
    {

        if (preorder.size() == 0)
            return NULL;

        TreeNode *root = new TreeNode(preorder[0]);

        vector<int> leftIn, rightIn, leftPr, rightPr;

        int i = 0;

        for (i = 0; i < inorder.size(); i++)
        {
            if (preorder[0] == inorder[i])
                break;

            leftIn.push_back(inorder[i]);
            leftPr.push_back(preorder[i + 1]);
        }

        for (i = i + 1; i < inorder.size(); i++)
        {
            rightIn.push_back(inorder[i]);
            rightPr.push_back(preorder[i]);
        }

        /* for(auto&x : leftIn)
         cout<<x<<" ";
         cout<<endl;

         for(auto&x : rightIn)
         cout<<x<<" ";
         cout<<endl;
 */
        root->left = buildTree(leftPr, leftIn);
        root->right = buildTree(rightPr, rightIn);

        return root;
    }
};