class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {

        vector<int> prev(amount + 1, 1e9);

        prev[0] = 0;

        for (int i = 1; i <= coins.size(); i++)
        {
            vector<int> cur(amount + 1, 0);

            for (int j = 0; j <= amount; j++)
            {
                int ntake = prev[j];
                int take = 1e9;

                if (coins[i - 1] <= j)
                    take = 1 + cur[j - coins[i - 1]];

                cur[j] = min(ntake, take);
            }
            prev = cur;
        }

        return prev[amount] == 1e9 ? -1 : prev[amount];
    }
};