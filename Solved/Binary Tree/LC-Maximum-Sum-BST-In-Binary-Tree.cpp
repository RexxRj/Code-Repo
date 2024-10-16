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
class NodeInfo
{
public:
    int minVal, maxVal, sum;
    NodeInfo(int minV, int maxV, int S)
    {
        this->minVal = minV;
        this->maxVal = maxV;
        this->sum = S;
    }

    void display()
    {
        cout << "min: " << minVal << endl
             << "max: " << maxVal << endl
             << "sum: " << sum << endl;
    }
};

class Solution
{
    int res = 0;
    NodeInfo solve(TreeNode *root)
    {
        if (root == NULL)
        {
            return NodeInfo(INT_MAX, INT_MIN, 0);
        }

        NodeInfo lf = solve(root->left);
        NodeInfo rt = solve(root->right);

        /* cout<<"root: "<<root->val<<endl;
         cout<<"lf"<<endl;
         lf.display();
         cout<<"rf"<<endl;
         rt.display();
         cout<<endl;*/

        if (root->val <= lf.maxVal || root->val >= rt.minVal)
        {
            // cout<<"Not BST"<<endl;
            return NodeInfo((long)INT_MIN, (long)INT_MAX, max(0, max(lf.sum, rt.sum)));
        }
        // cout<<"BST\n"<<endl;
        res = max(res, root->val + lf.sum + rt.sum);

        return NodeInfo(min(root->val, (int)lf.minVal), max(root->val, (int)rt.maxVal), root->val + lf.sum + rt.sum);
    }

public:
    int maxSumBST(TreeNode *root)
    {

        solve(root);

        return res;
    }
};