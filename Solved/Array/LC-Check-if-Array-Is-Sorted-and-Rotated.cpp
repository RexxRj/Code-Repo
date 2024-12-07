class Solution
{
public:
    bool check(vector<int> &nums)
    {

        int cnt = 0, n = nums.size();

        for (int i = 1; i < n; i++)
        {
            if (nums[i] < nums[i - 1])
                cnt++;
        }

        if (nums[0] < nums[n - 1])
            cnt++;

        // check number of violations is less or equal to 1
        return cnt <= 1;
    }
};