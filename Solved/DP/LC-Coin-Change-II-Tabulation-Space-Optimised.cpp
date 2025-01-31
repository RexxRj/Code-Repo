// Mod to help with overflow due to unnecessary calculations of amount.

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> prev(amount + 1, 0), cur(amount + 1, 0);
        int MOD = INT_MAX;

        prev[0] = 1;

        for (int i = 1; i <= coins.size(); i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                long ntake = prev[j];
                long take = 0;

                if (coins[i - 1] <= j)
                    take = cur[j - coins[i - 1]];

                cur[j] = (ntake + take) % MOD;
            }
            prev = cur;
        }

        return prev[amount];
    }
};