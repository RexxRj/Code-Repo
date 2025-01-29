class Solution
{

    vector<int> findAllSubsets(int l, int r, vector<int> &nums)
    {
        int N = r - l;
        vector<int> ans;

        for (int i = 0; i < (1 << N); i++)
        {
            int ind = i, j = l, sum = 0;
            while (ind)
            {
                if (ind & 1)
                    sum += nums[j];
                j++;
                ind = ind >> 1;
            }

            ans.push_back(sum);
        }

        return ans;
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {

        int total = accumulate(nums.begin(), nums.end(), 0);
        vector<int> left, right;
        int n = nums.size();

        left = findAllSubsets(0, n / 2, nums);
        right = findAllSubsets(n / 2, n, nums);

        sort(right.begin(), right.end());
        int ans = 0;

        for (int i = 0; i < left.size(); i++)
        {
            int s1 = left[i];
            double s2 = (double)(total + target - 2 * s1) / 2;

            auto itr = lower_bound(right.begin(), right.end(), s2);

            while (itr != right.end() && (*itr) == s2)
            {
                ans++;
                itr++;
            }
        }

        return ans;
    }
};