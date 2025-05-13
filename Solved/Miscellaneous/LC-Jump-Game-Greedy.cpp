class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        int maxInd = 0, n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (i > maxInd)
                return false;

            if (maxInd >= nums.size() - 1)
                return true;

            maxInd = max(maxInd, i + nums[i]);
        }

        return true;
    }
};