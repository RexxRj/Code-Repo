class Solution
{

    void solve(int ind, vector<int> &nums, vector<int> &res, vector<vector<int>> &ans)
    {
        ans.push_back(res);

        for (int i = ind; i < nums.size(); i++)
        {
            if (i != ind && nums[i] == nums[i - 1])
                continue;

            res.push_back(nums[i]);
            solve(i + 1, nums, res, ans);
            res.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {

        vector<vector<int>> ans;
        vector<int> res;

        sort(nums.begin(), nums.end());

        solve(0, nums, res, ans);

        return ans;
    }
};