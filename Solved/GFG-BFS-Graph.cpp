/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    unordered_map<Node *, Node *> m;
    Node *cloneGraph(Node *node)
    {

        if (node == NULL)
            return NULL;

        Node *clone = new Node(node->val);
        vector<Node *> nbr;

        m[node] = clone;

        for (auto &x : node->neighbors)
        {
            if (m.find(x) != m.end())
                nbr.push_back(m[x]);
            else
                nbr.push_back(cloneGraph(x));
        }

        clone->neighbors = nbr;

        return clone;
    }
};