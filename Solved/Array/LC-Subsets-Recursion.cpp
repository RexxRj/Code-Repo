class Solution
{

    void solve(int ind, vector<int> &nums, vector<int> res, vector<vector<int>> &ans)
    {
        if (ind == nums.size())
        {
            ans.push_back(res);
            return;
        }

        solve(ind + 1, nums, res, ans);
        res.push_back(nums[ind]);
        solve(ind + 1, nums, res, ans);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {

        vector<vector<int>> ans;

        solve(0, nums, vector<int>(), ans);

        return ans;
    }
};