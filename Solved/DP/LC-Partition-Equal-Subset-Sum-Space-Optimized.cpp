class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {

        int target = 0;

        for (int i = 0; i < nums.size(); i++)
            target += nums[i];

        if (target & 1)
            return false;

        target = target / 2;

        vector<int> prev(target + 1, 0), cur(target + 1, 0);
        prev[0] = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j <= target; j++)
            {
                if (nums[i] > j)
                    cur[j] = prev[j];
                else
                    cur[j] = prev[j] || prev[j - nums[i]];
            }
            prev = cur;
        }

        return cur[target];
    }
};