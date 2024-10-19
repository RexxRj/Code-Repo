#include <bits/stdc++.h>

struct Node
{

    Node *links[26] = {};
    int cntEndsWth = 0;
    int cntPrefix = 0;

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

    void setEnd()
    {
        cntEndsWth++;
    }

    void setPrefix()
    {
        cntPrefix++;
    }

    int getEnd()
    {
        return cntEndsWth;
    }

    int getPrefix()
    {
        return cntPrefix;
    }

    void eraseEnd()
    {
        cntEndsWth--;
    }

    void erasePrefix()
    {
        cntPrefix--;
    }
};

class Trie
{

    Node *root;

public:
    Trie()
    {
        // Write your code here.
        root = new Node;
    }

    void insert(string &word)
    {
        // Write your code here.
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node);
            }
            node = node->get(word[i]);
            node->setPrefix();
        }

        node->setEnd();
    }

    int countWordsEqualTo(string &word)
    {
        // Write your code here.
        Node *node = root;

        for (int i = 0; i < word[i]; i++)
        {
            if (!node->containsKey(word[i]))
                return 0;

            node = node->get(word[i]);
        }

        return node->getEnd();
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                return 0;

            node = node->get(word[i]);
        }

        return node->getPrefix();
    }

    void erase(string &word)
    {
        // Write your code here.
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                return;

            node = node->get(word[i]);
            node->erasePrefix();
        }

        node->eraseEnd();
    }
};
