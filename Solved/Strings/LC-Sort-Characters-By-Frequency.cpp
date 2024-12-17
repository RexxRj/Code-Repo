class Solution
{
public:
    string frequencySort(string s)
    {

        unordered_map<char, int> m;

        for (int i = 0; i < s.length(); i++)
            m[s[i]]++;

        priority_queue<pair<int, char>> pq;

        for (auto &x : m)
        {
            pq.push(make_pair(x.second, x.first));
        }

        string res = "";

        while (!pq.empty())
        {
            auto el = pq.top();
            pq.pop();
            int freq = el.first;
            char c = el.second;

            while (freq)
            {
                res += c;
                freq--;
            }
        }

        return res;
    }
};