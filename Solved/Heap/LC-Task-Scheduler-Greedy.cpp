class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {

        vector<int> freq(26, 0);

        for (auto &x : tasks)
            freq[x - 'A']++;

        priority_queue<int> pq;

        for (auto &x : freq)
            if (x != 0)
                pq.push(x);

        int time = 0;

        while (!pq.empty())
        {
            vector<int> store;
            int taskCount = 0, cycle = n + 1;

            while (cycle-- && !pq.empty())
            {
                int f = pq.top();
                pq.pop();

                if (f > 1)
                    store.push_back(f - 1);
                taskCount++;
            }

            for (auto &x : store)
                pq.push(x);

            time += pq.empty() ? taskCount : n + 1;
        }

        return time;
    }
};