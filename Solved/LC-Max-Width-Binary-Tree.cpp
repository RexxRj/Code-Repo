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
    int widthOfBinaryTree(TreeNode *root)
    {

        if (root == NULL)
            return 0;

        queue<pair<TreeNode *, long long>> q;

        int ans = 1;

        q.push({root, 0});

        while (!q.empty())
        {
            int s = q.size();
            long long minn = q.front().second;

            int first, last;

            for (int i = 0; i < s; i++)
            {
                TreeNode *temp = q.front().first;
                long long index = q.front().second - minn;
                q.pop();

                if (i == 0)
                    first = index;
                if (i == s - 1)
                    last = index;

                if (temp->left)
                    q.push({temp->left, 2 * index + 1});
                if (temp->right)
                    q.push({temp->right, 2 * index + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};