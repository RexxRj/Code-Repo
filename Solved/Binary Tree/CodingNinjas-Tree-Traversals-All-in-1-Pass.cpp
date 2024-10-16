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
vector<vector<int>> getTreeTraversal(TreeNode *root)
{

    // Write your code here.

    if (root == NULL)
        return {};

    vector<vector<int>> ans(3, vector<int>());

    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        TreeNode *temp = st.top().first;
        int num = st.top().second;

        st.pop();

        if (num == 1)
        {
            ans[1].push_back(temp->data);
            st.push({temp, ++num});
            if (temp->left)
                st.push({temp->left, 1});
        }
        else if (num == 2)
        {
            ans[0].push_back(temp->data);
            st.push({temp, ++num});
            if (temp->right)
                st.push({temp->right, 1});
        }
        else
        {
            ans[2].push_back(temp->data);
        }
    }

    return ans;
}