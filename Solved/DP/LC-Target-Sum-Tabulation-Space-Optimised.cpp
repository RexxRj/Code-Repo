class Solution
{

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {

        int total = accumulate(nums.begin(), nums.end(), 0);

        if ((total + target) < 0 || (total - target) < 0)
            return 0;

        if ((total + target) % 2 == 1)
            return 0;

        int s1 = (total + target) / 2;

        vector<int> prev(s1 + 1, 0), cur(s1 + 1, 0);
        prev[0] = 1;

        for (int i = 1; i <= nums.size(); i++)
        {
            for (int j = 0; j <= s1; j++)
            {
                int ntake = prev[j];
                int take = 0;
                if (nums[i - 1] <= j)
                    take = prev[j - nums[i - 1]];

                cur[j] = ntake + take;
            }
            prev = cur;
        }

        return prev[s1];
    }
};