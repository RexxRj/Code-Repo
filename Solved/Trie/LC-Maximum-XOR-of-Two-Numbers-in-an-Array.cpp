struct Node
{
    Node *lists[2] = {};

    bool containsKey(int bit)
    {
        return lists[bit] != NULL;
    }

    void put(int bit, Node *node)
    {
        lists[bit] = node;
    }

    Node *get(int bit)
    {
        return lists[bit];
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

    void insert(int num)
    {
        Node *node = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            if (!node->containsKey(bit))
            {
                node->put(bit, new Node);
            }

            node = node->get(bit);
        }
    }

    int getMax(int num)
    {
        Node *node = root;
        int maxNum = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            if (node->containsKey(1 - bit))
            {

                maxNum = maxNum | (1 << i);
                node = node->get(1 - bit);
            }
            else
                node = node->get(bit);
        }

        return maxNum;
    }
};

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {

        Trie ob;

        for (int i = 0; i < nums.size(); i++)
        {
            ob.insert(nums[i]);
        }

        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            ans = max(ans, ob.getMax(nums[i]));
        }

        return ans;
    }
};