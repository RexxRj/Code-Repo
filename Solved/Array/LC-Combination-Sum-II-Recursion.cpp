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
            if (i != ind && arr[i] == arr[i - 1])
                continue;
            if (arr[i] <= target)
            {
                res.push_back(arr[i]);
                solve(i + 1, target - arr[i], arr, res, ans);
                res.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &arr, int target)
    {

        vector<vector<int>> ans;
        vector<int> res;

        sort(arr.begin(), arr.end());

        solve(0, target, arr, res, ans);

        return ans;
    }
};
