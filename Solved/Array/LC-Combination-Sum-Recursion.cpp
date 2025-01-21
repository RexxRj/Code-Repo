class Solution
{

    void solve(int ind, int target, vector<int> &arr, vector<int> &res, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(res);
            return;
        }

        for (int i = ind; i < arr.size(); i++)
        {
            if (arr[i] <= target)
            {
                res.push_back(arr[i]);
                solve(i, target - arr[i], arr, res, ans);
                res.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &arr, int target)
    {

        vector<vector<int>> ans;
        vector<int> res;

        solve(0, target, arr, res, ans);

        return ans;
    }
};