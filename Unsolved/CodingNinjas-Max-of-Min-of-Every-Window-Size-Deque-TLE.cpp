#include <bits/stdc++.h>
vector<int> maxMinWindow(vector<int> a, int n)
{
    // Write your code here.
    vector<int> ans;
    for (int k = 1; k <= n; k++)
    {
        deque<int> dq;
        int maxW = INT_MIN;
        for (int i = 0; i < a.size(); i++)
        {
            while (!dq.empty() && dq.front() < i - k + 1)
                dq.pop_front();

            while (!dq.empty() && a[dq.back()] >= a[i])
                dq.pop_back();

            dq.push_back(i);

            if (i - k + 1 >= 0)
                maxW = max(maxW, a[dq.front()]);
        }
        ans.push_back(maxW);
    }

    return ans;
}
/*k = 1
1 2 3 4
0 1 2 3




0
maxW =*/