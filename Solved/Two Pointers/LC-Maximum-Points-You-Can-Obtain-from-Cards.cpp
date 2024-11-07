class Solution
{
public:
    int maxScore(vector<int> &nums, int k)
    {

        int score = 0, lsum = 0, rsum = 0;

        for (int i = 0; i < k; i++)
            lsum += nums[i];

        score = lsum;
        int rInd = nums.size() - 1;

        for (int i = k - 1; i >= 0; i--)
        {
            lsum -= nums[i];
            rsum += nums[rInd];
            rInd--;
            score = max(score, lsum + rsum);
        }

        return score;
    }
};