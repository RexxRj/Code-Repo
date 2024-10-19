struct Node
{

    Node *links[26] = {};

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
};

int countDistinctSubstrings(string &s)
{
    //    Write your code here.

    int cnt = 1;

    Node *root = new Node;

    for (int i = 0; i < s.size(); i++)
    {
        Node *node = root;

        for (int j = i; j < s.size(); j++)
        {
            if (!node->containsKey(s[j]))
            {
                node->put(s[j], new Node);
                cnt++;
            }

            node = node->get(s[j]);
        }
    }

    return cnt;
}