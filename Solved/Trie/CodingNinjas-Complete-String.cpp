#include <bits/stdc++.h>

struct Node
{
    Node *links[26] = {};
    bool flg = false;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flg = true;
    }

    bool isEnd()
    {
        return flg;
    }
};

class Trie
{

    Node *root;

public:
    Trie()
    {
        root = new Node;
    }

    void insert(string word)
    {

        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node);
            }

            node = node->get(word[i]);
        }

        node->setEnd();
    }

    bool checkWithPrefix(string prefix)
    {

        Node *node = root;

        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containsKey(prefix[i]))
                return false;

            node = node->get(prefix[i]);
            if (node->isEnd() == false)
                return false;
        }

        return true;
    }
};

string completeString(int n, vector<string> &a)
{
    // Write your code here.

    Trie ob;

    for (int i = 0; i < n; i++)
    {
        ob.insert(a[i]);
    }

    string ans = "";

    for (int i = 0; i < n; i++)
    {
        if (ob.checkWithPrefix(a[i]))
        {
            if (a[i].size() > ans.size() || (a[i].size() == ans.size() && a[i] < ans))
                ans = a[i];
        }
    }

    return ans == "" ? "None" : ans;
}