class Solution
{

    void solve(int ind, int &sum, int &k, int &n, vector<int> &res, vector<vector<int>> &ans)
    {
        if (res.size() == k)
        {
            if (sum == n)
                ans.push_back(res);
            return;
        }

        for (int i = ind + 1; i < 10; i++)
        {
            sum += i;
            res.push_back(i);
            solve(i, sum, k, n, res, ans);
            res.pop_back();
            sum -= i;
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {

        vector<vector<int>> ans;
        vector<int> res;
        int sum = 0;

        solve(0, sum, k, n, res, ans);

        return ans;
    }
};