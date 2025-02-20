class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {

        int len = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (len == 0 || nums[len - 1] < nums[i])
                nums[len++] = nums[i];
            else
                *lower_bound(nums.begin(), nums.begin() + len, nums[i]) = nums[i];
        }

        return len;
    }
};