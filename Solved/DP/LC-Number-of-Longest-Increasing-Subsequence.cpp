class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> LIS(n, 1), tempcnt(n, 1);
        int maxLen = 1, cnt = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (LIS[i] < 1 + LIS[j])
                    {
                        LIS[i] = 1 + LIS[j];
                        tempcnt[i] = tempcnt[j];
                    }
                    else if (LIS[i] == 1 + LIS[j])
                    {
                        tempcnt[i] += tempcnt[j];
                    }
                }
            }

            if (maxLen < LIS[i])
            {
                maxLen = LIS[i];
                cnt = tempcnt[i];
            }
            else if (maxLen == LIS[i])
            {
                cnt += tempcnt[i];
            }
        }

        return cnt;
    }
};