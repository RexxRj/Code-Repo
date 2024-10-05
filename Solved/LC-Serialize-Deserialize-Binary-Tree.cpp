/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "";

        string str = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();

            if (cur == NULL)
                str.append("#,");
            else
                str.append(to_string(cur->val) + ",");
            if (cur != NULL)
            {
                q.push(cur->left);
                q.push(cur->right);
            }
        }

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {

        if (data == "")
            return NULL;

        stringstream s(data);

        string str;
        getline(s, str, ',');

        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();

            getline(s, str, ',');

            if (str == "#")
                cur->left = NULL;
            else
            {
                cur->left = new TreeNode(stoi(str));
                q.push(cur->left);
            }

            getline(s, str, ',');

            if (str == "#")
                cur->right = NULL;
            else
            {
                cur->right = new TreeNode(stoi(str));
                q.push(cur->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));