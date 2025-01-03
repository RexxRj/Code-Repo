class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {

        int n = nums.size();

        vector<vector<int>> ans;

        for (int i = 0; i < (1 << n); i++)
        {
            int ind = i, j = 0;
            vector<int> res;

            while (ind)
            {
                if (ind & 1)
                    res.push_back(nums[j]);
                ind = ind >> 1;
                j++;
            }

            ans.push_back(res);
        }

        return ans;
    }
};