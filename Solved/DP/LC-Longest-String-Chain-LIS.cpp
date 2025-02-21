class Solution
{

    bool check(string &a, string &b)
    {
        // cout<<a<<" "<<b<<endl;
        if (a.size() != b.size() + 1)
            return false;

        int i = 0, j = 0;

        while (i < a.size())
        {
            if (a[i] != b[j])
            {
                i++;
            }
            else
            {
                i++;
                j++;
            }
        }

        if (i == a.size() && j == b.size())
            return true;
        return false;
    }

public:
    int longestStrChain(vector<string> &words)
    {

        int n = words.size();
        int maxChain = 1;
        vector<int> LIS(n, 1);

        sort(words.begin(), words.end(), [&](string &a, string &b)
             { return a.size() < b.size(); });

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (check(words[i], words[j]))
                {
                    // cout<<"true "<<LIS[j]<<" "<<LIS[i]<<endl;
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
                }
            }

            maxChain = max(maxChain, LIS[i]);
        }

        return maxChain;
    }
};