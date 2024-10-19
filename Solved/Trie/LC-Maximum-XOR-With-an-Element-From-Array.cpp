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
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {

        Trie ob;

        vector<int> ans(queries.size(), -1);

        vector<pair<int, pair<int, int>>> offQ;

        for (int i = 0; i < queries.size(); i++)
        {
            offQ.push_back({queries[i][1], {queries[i][0], i}});
        }

        sort(offQ.begin(), offQ.end());

        sort(nums.begin(), nums.end());

        int ind = 0;

        for (int i = 0; i < offQ.size(); i++)
        {
            int m = offQ[i].first;
            int x = offQ[i].second.first;
            int qInd = offQ[i].second.second;

            while (ind < nums.size() && nums[ind] <= m)
            {
                ob.insert(nums[ind]);
                ind++;
            }

            if (ind != 0)
                ans[qInd] = ob.getMax(x);
        }

        return ans;
    }
};