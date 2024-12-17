class Solution
{

    struct compare
    {
        bool operator()(pair<int, pair<int, char>> &a, pair<int, pair<int, char>> &b)
        {
            return a.first != b.first ? a.first > b.first : a.second.first < b.second.first;
        }
    };

    void reduce_av(priority_queue<pair<int, pair<int, char>>, vector<pair<int, pair<int, char>>>, compare> &pq)
    {
        priority_queue<pair<int, pair<int, char>>, vector<pair<int, pair<int, char>>>, compare> pq2;

        while (!pq.empty())
        {
            auto el = pq.top();
            pq.pop();
            int av = el.first;
            int freq = el.second.first;
            char c = el.second.second;

            if (av != 0)
                av--;

            pq2.push(make_pair(av, make_pair(freq, c)));
        }

        while (!pq2.empty())
        {
            auto el = pq2.top();
            pq2.pop();
            int av = el.first;
            int freq = el.second.first;
            char c = el.second.second;

            pq.push(make_pair(av, make_pair(freq, c)));
        }
    }

public:
    int leastInterval(vector<char> &tasks, int n)
    {

        priority_queue<pair<int, pair<int, char>>, vector<pair<int, pair<int, char>>>, compare> pq;

        vector<int> chars(26, 0);

        for (auto &x : tasks)
            chars[x - 'A']++;

        for (int i = 0; i < 26; i++)
        {
            int c = 'A' + i;
            int freq = chars[i];
            if (freq != 0)
                pq.push(make_pair(0, make_pair(freq, c)));
        }

        int intervals = 0;

        while (!pq.empty())
        {
            auto el = pq.top();
            pq.pop();
            int av = el.first;
            int freq = el.second.first;
            char c = el.second.second;

            intervals++;
            if (av == 0)
            {
                av = n;
                freq--;
            }
            else
                av--;
            // cout<<"intervals: "<<intervals<<" av: "<<av<<" freq: "<<freq<<" char: "<<c<<endl;
            reduce_av(pq);

            if (freq != 0)
                pq.push(make_pair(av, make_pair(freq, c)));
        }

        return intervals;
    }
};
